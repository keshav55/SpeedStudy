/*
 *  SPCurrentUser.h
 *  Current Spritz User
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 SPCurrentUser is a model object that contains basic user information.
 */

@interface SPCurrentUser : NSObject

/**
 Unique identifier specific to the currently logged in user.
 */

@property (nonatomic, retain) NSString * userID;

/**
 Email address of the currently logged in user.
 */

@property (nonatomic, retain) NSString * emailAddress;

/**
 *  User name of the currently logged in user.
 */

@property (nonatomic, retain) NSString * userName;

@end
