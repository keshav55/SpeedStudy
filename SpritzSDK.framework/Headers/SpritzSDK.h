//
//  SpritzSDK.h
//  SpritzSDK
//
//  Created by Drew Ingebretsen on 9/9/14.
//  Copyright (c) 2014 Drew Ingebretsen. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for SpritzSDK.
FOUNDATION_EXPORT double SpritzSDKVersionNumber;

//! Project version string for SpritzSDK.
FOUNDATION_EXPORT const unsigned char SpritzSDKVersionString[];

#import "SPActionButton.h"
#import "SPBaseView.h"
#import "SPControlView.h"
#import "SPContentCache.h"
#import "SPCurrentUser.h"
#import "SPFullControlView.h"
#import "SPPlainTextSource.h"
#import "SPSource.h"
#import "SPURLSource.h"
#import "SPViewDelegate.h"

/**
 *  SpritzSDK is the entry point for communication with the Spritz servers. It lets you set your SDK Client IDs and contains utility methods for user management.
 */

@interface SpritzSDK : NSObject

/**
 *  Retrieves the currently logged in user or nil if there is no user currently logged in.
 *
 *  @param completionBlock This block is called after the user is retrieved.
 */

+ (void)getLoggedInUser:(void(^)(SPCurrentUser *user, NSError *error))completionBlock;

/**
 *  Displays the user login dialog box, with an optional callback handling any errors with login. If this is never called by the developer, it is called automatically the first time the user tries to interact with the SpritzSDK.
 *
 *  @param completionBlock This block is called when the user completes or cancels the dialog box.
 */

+ (void)loginUser:(void(^)(BOOL success, NSError *error))completionBlock;

/**
 *  Logs out the current user and destroys the user session.
 *
 *  @param completionBlock This block is called when the session is destroyed.
 */

+ (void)logoutUser:(void(^)(NSError *error))completionBlock;

/**
 *  Sets your application Client ID and Client Secret for the SpritzSDK. This must be done before any other actions can be performed. If you don’t have a Client ID or Client Secret, create one at http://www.spritzinc.com/developers/.
 *
 *  @warning If you fail to set the ClientID or ClientSecret, your app will crash with an assertion failure on SDK use. Setting an invalid ClientID or ClientSecret will result in an API error message.
 *
 *  @param clientID Your application's unique Client ID
 *  @param clientSecret Your application's unique Client Secret.
 */

+ (void)setClientID:(NSString *)clientID clientSecret:(NSString *)clientSecret;

/**
 *  Returns if a local engine to process text for Spritzing is available. For public SDK releases this will be set to NO.
 */

+ (BOOL)isLocalEngineAvailable;

@end



