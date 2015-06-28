/*
 *  SPControlView.h
 *  Spritz Control View
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import "SPBaseView.h"

/** SPControlView is a subclass of the SPBaseView that implements simple UI controls instead of requiring  developers to implement their own controls. If a user taps on the SPControlView, the SPControlView control automatically pauses the current text stream and provides buttons to rewind, go back a sentence, resume, and change settings. A developer can also define custom setting buttons which can be added. The SPControlView will prompt the user to login with their Spritz account, or create one, before they can Spritz content.
 */

@interface SPControlView : SPBaseView

/**
 Lets developers specify additional buttons in the settings panel of the SPControlView.
 
 @param buttons An NSArray of SPActionButtons to be added to the SPControlView. The buttons become visible when the user clicks the “Settings” button of the SPControlView.
 
 */

- (void)addSpritzActionButtons:(NSArray *)buttons;

@end
