/*
 *  SPPlainTextSource.h
 *  Spritz SDK
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "SPSource.h"

/**
 SPPlainTextSource is an SPSource subclass which can be used for defining a plain text string as the source of a Spritz control.
 */

@interface SPPlainTextSource : SPSource

/**
 The text of the SPPlainTextSource.
 */

@property (nonatomic, strong) NSString *text;

@property (nonatomic, strong) NSLocale *locale;

/**
 Creates a new SPPlainTextSource with the specified text string.
 */

+(SPPlainTextSource*)plainTextSourceWithText:(NSString*)text;

/**
 Initialized a new SPPlainTextSource with the specified text string.
 */

-(instancetype)initWithText:(NSString*)text;

@end
