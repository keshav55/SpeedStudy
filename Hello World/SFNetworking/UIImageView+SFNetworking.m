// UIImageView+SFNetworking.m
//
// Copyright (c) 2011 Gowalla (http://gowalla.com/)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

#if defined(__IPHONE_OS_VERSION_MIN_REQUIRED)
#import "UIImageView+SFNetworking.h"

@interface SFImageCache : NSCache
- (UIImage *)cachedImageForRequest:(NSURLRequest *)request;
- (void)cacheImage:(UIImage *)image
        forRequest:(NSURLRequest *)request;
@end

#pragma mark -

static char kSFImageRequestOperationObjectKey;

@interface UIImageView (_SFNetworking)
@property (readwrite, nonatomic, strong, setter = SF_setImageRequestOperation:) SFImageRequestOperation *SF_imageRequestOperation;
@end

@implementation UIImageView (_SFNetworking)
@dynamic SF_imageRequestOperation;
@end

#pragma mark -

@implementation UIImageView (SFNetworking)

- (SFHTTPRequestOperation *)SF_imageRequestOperation {
    return (SFHTTPRequestOperation *)objc_getAssociatedObject(self, &kSFImageRequestOperationObjectKey);
}

- (void)SF_setImageRequestOperation:(SFImageRequestOperation *)imageRequestOperation {
    objc_setAssociatedObject(self, &kSFImageRequestOperationObjectKey, imageRequestOperation, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

+ (NSOperationQueue *)SF_sharedImageRequestOperationQueue {
    static NSOperationQueue *_SF_imageRequestOperationQueue = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _SF_imageRequestOperationQueue = [[NSOperationQueue alloc] init];
        [_SF_imageRequestOperationQueue setMaxConcurrentOperationCount:NSOperationQueueDefaultMaxConcurrentOperationCount];
    });

    return _SF_imageRequestOperationQueue;
}

+ (SFImageCache *)SF_sharedImageCache {
    static SFImageCache *_SF_imageCache = nil;
    static dispatch_once_t oncePredicate;
    dispatch_once(&oncePredicate, ^{
        _SF_imageCache = [[SFImageCache alloc] init];
    });

    return _SF_imageCache;
}

#pragma mark -

- (void)setImageWithURL:(NSURL *)url {
    [self setImageWithURL:url placeholderImage:nil];
}

- (void)setImageWithURL:(NSURL *)url
       placeholderImage:(UIImage *)placeholderImage
{
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request addValue:@"image/*" forHTTPHeaderField:@"Accept"];

    [self setImageWithURLRequest:request placeholderImage:placeholderImage success:nil failure:nil];
}

- (void)setImageWithURLRequest:(NSURLRequest *)urlRequest
              placeholderImage:(UIImage *)placeholderImage
                       success:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, UIImage *image))success
                       failure:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error))failure
{
    [self cancelImageRequestOperation];

    UIImage *cachedImage = [[[self class] SF_sharedImageCache] cachedImageForRequest:urlRequest];
    if (cachedImage) {
        self.SF_imageRequestOperation = nil;

        if (success) {
            success(nil, nil, cachedImage);
        } else {
            self.image = cachedImage;
        }
    } else {
        if (placeholderImage) {
            self.image = placeholderImage;
        }

        SFImageRequestOperation *requestOperation = [[SFImageRequestOperation alloc] initWithRequest:urlRequest];
		
#ifdef _SFNETWORKING_ALLOW_INVALID_SSL_CERTIFICATES_
		requestOperation.allowsInvalidSSLCertificate = YES;
#endif
		
        [requestOperation setCompletionBlockWithSuccess:^(SFHTTPRequestOperation *operation, id responseObject) {
            if ([urlRequest isEqual:[self.SF_imageRequestOperation request]]) {
                if (self.SF_imageRequestOperation == operation) {
                    self.SF_imageRequestOperation = nil;
                }

                if (success) {
                    success(operation.request, operation.response, responseObject);
                } else if (responseObject) {
                    self.image = responseObject;
                }
            }

            [[[self class] SF_sharedImageCache] cacheImage:responseObject forRequest:urlRequest];
        } failure:^(SFHTTPRequestOperation *operation, NSError *error) {
            if ([urlRequest isEqual:[self.SF_imageRequestOperation request]]) {
                if (self.SF_imageRequestOperation == operation) {
                    self.SF_imageRequestOperation = nil;
                }

                if (failure) {
                    failure(operation.request, operation.response, error);
                }
            }
        }];

        self.SF_imageRequestOperation = requestOperation;

        [[[self class] SF_sharedImageRequestOperationQueue] addOperation:self.SF_imageRequestOperation];
    }
}

- (void)cancelImageRequestOperation {
    [self.SF_imageRequestOperation cancel];
    self.SF_imageRequestOperation = nil;
}

@end

#pragma mark -

static inline NSString * SFImageCacheKeyFromURLRequest(NSURLRequest *request) {
    return [[request URL] absoluteString];
}

@implementation SFImageCache

- (UIImage *)cachedImageForRequest:(NSURLRequest *)request {
    switch ([request cachePolicy]) {
        case NSURLRequestReloadIgnoringCacheData:
        case NSURLRequestReloadIgnoringLocalAndRemoteCacheData:
            return nil;
        default:
            break;
    }

	return [self objectForKey:SFImageCacheKeyFromURLRequest(request)];
}

- (void)cacheImage:(UIImage *)image
        forRequest:(NSURLRequest *)request
{
    if (image && request) {
        [self setObject:image forKey:SFImageCacheKeyFromURLRequest(request)];
    }
}

@end

#endif
