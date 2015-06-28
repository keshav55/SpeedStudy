/*
 *  SPURLSource.h
 *  Spritz SDK
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "SPSource.h"

/**
 SPURLSource is an SPSource subclass which can be used for spritzing the content of a specific URL. Both web URLs as well as local file URLs are supported.
 */

@interface SPURLSource : SPSource

/**
 An optional CSS selector. This tells the spritz server to only spritz content from the HTML elements matched by the passed in CSS selector. Multiple CSS selectors can be passed in by seperating the CSS selectors with a comma.
 */

@property (nonatomic, strong) NSString *cssSelector;

/**
 The URL of the SPURLSource.
 */

@property (nonatomic, strong) NSURL *url;

/**
 Creates a new SPURLSource with the specified NSURL.
 */

+(SPURLSource*)URLSourceWithURL:(NSURL*)url;

/**
 Creates a new SPPlainTextSource with the specified text string.
 */

+(SPURLSource*)URLSourceWithString:(NSString*)string;

/**
 Initializes a new SPURLSource with the specified text string.
 */

-(instancetype)initWithString:(NSString*)string;

/**
 Creates a new SPURLSource with the specified NSURL.
 */

-(instancetype)initWithURL:(NSURL*)url;

@end
