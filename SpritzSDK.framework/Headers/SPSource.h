/*
 *  SPSource.h
 *  Spritz SDK
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, SPCachePolicy) {
    /**
     Download the source without any caching. This is the default behavior.
     */
    
    SPCachePolicyDownloadOnly = 0,
    
    /**
     If an entry exists in the cache with the cache identifier of the SPSource, load the content from the cache. Otherwise download the Spritz content and store it in the cache.
     */
    
    SPCachePolicyCacheElseDownload = 1,
    
    /**
    Download the source and store it in the cache. If the download fails, load the content from the cache if it exists.
     */
    
    SPCachePolicyDownloadThenCache = 2,
    
    /**
     Only load the content from the cache. If it doesn't exist in the cache then error.
     */
    
    SPCachePolicyCacheOnly = 4
};

/**
 SPSource is the base object for all SPSource objects, including the SPURLSource and SPPlainTextSource.
 */

@interface SPSource: NSObject

/**
 The cache policy for the SPSource object.
 */

@property (nonatomic, assign) SPCachePolicy cachePolicy;

/**
 The cache identifier. By default this is hash of the plain text or URL string of the SPSource. A developer can supply their own identifier for their own purposes if needed.
 @warning The cache identifier is what determines how the content is stored in the cache, not the content itself. That means if content with the same identifier but different content is stored in the cache, it will be overwrite the previous content stored in the cache, or load the different content. It is recommended to guarentee uniqueness to either use the default identifer or use a hashing algorithm that guarentees uniqueness.
 */

@property (nonatomic, strong) NSString *cacheIdentifier;

@end
