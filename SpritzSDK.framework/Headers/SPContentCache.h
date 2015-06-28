/*
 *  SPContentCache.h
 *  Spritz Content Cache
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 SPContentCache provides several static methods for interacting with the shared content cache of the application. Through these methods a developer can set cache limits, do direct cache management, and manually cache sources.
 */

@class SPSource;

@interface SPContentCache : NSObject

/**
 Caches the specified source from the Spritz server.
 @param source The source object to cache.
 @param completionBlock The completion block after the SDK finished caching the source. It returns the cacheIdentifier, or nil if there was an error.
 @warning This method will cache the source regardless of what the cache policy is set to.
 */

+ (void)cacheSource:(SPSource*)source completion:(void(^)(NSString *cacheIdentifier, NSError *error))completionBlock;

/**
 Returns the current disk usage of the content cache.
 */

+ (NSInteger)currentDiskUsage;

/**
 Returns the current disk limit of the cache, in bytes, before the cache automatically clears old entries. The default disk limit is 50 megabytes.
 */

+ (NSInteger)diskCapacity;

/**
 Returns a list of all identifiers currently in the content cache. By default the cache identifier is a hash of the text source or url of the source. However a developer can specify their own cache identifer if desired. 
 @warning There currently is no way to get the associated plain text associated with an identifier. A developer must store this independently.
 */

+ (NSArray*)getAllIdentifersInCache;

/**
 Removes all cached sources, completely clearing the content cache.
 */

+ (void)removeAllCachedSources;

/**
 Removes the cached source with the specified cache identifier.
 @param The cache identifier of the cached source to remove.
 */

+ (void)removeCachedSourceWithIdentifier:(NSString*)cacheIdentifier;

/**
 Sets the disk limit of the cache, in bytes. When the disk limit is reached the cache will automatically clear older entries, as determined by date of access, until the limit disk limit is reached again. If the limit is set to -1 then there will be no disk constraints placed on the cache size.
 @param The cache identifier of the cached source to remove. The default disk limit is 50 megabytes.
 @warning The minimum cache size is 10 megabytes.
 */

+ (void)setDiskCapacity:(NSInteger)size;

@end
