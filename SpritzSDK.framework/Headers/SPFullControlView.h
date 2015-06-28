/*
 *  SPFullControlView.h
 *  Spritz Full Control View
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "SPBaseView.h"

/**
 SPFullControlView is a subclass of the SPBaseView that provides full Spritzing controls on it's face, including pause/resume, speed change, rewinding, and going back, login and logout. Because the SPFullControl has controls to login/logout, it does not require the user to login in order to Spritz content. There is a speed cap of 450 for unregistered users.
    @warning It is recommended that SPFullControlView implement's a minimum height of 135pts.
 */

@interface SPFullControlView : SPBaseView

/**
 Lets developers specify additional buttons in the settings panel of the SPControlView.
 
 @param buttons An NSArray of SPActionButtons to be added to the SPFullControlView. The buttons become visible when the user clicks the “wpm” button of the SPFullControlView.
 
 */

- (void)addSpritzActionButtons:(NSArray *)buttons;

/**
 The back button goes back one sentence. This property hides or unhides the back button. Defaults to YES.
 */

@property (nonatomic, assign) BOOL backButtonEnabled;

/**
 The forward button goes forward one sentence. This property hides or unhides the forward button. Defaults to NO.
 */

@property (nonatomic, assign) BOOL forwardButtonEnabled;

/**
 The play button goes pauses or resumes the content. This property hides or unhides the play button. Defaults to YES.
 */

@property (nonatomic, assign) BOOL playButtonEnabled;

/**
 The rewind button returns the user to the beginning of the content. This property hides or unhides the rewind button. Defaults to YES.
 */

@property (nonatomic, assign) BOOL rewindButtonEnabled;

/**
 The settings button presents the settings pane. This property hides or unhides the settings button. Defaults to YES.
 */

@property (nonatomic, assign) BOOL settingsButtonEnabled;

@end
