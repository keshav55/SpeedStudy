/*
 *  SPActionButton.h
 *  Spritz Action Button
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

/**
 SPActionButton class lets you create custom buttons and actions for the SPControlView. By creating an SPActionButton and adding it to an SPControlView, additional buttons will appear when the user selects 'Settings' on the SPControlView.
 */

#import <Foundation/Foundation.h>

@interface SPActionButton : NSObject

/**
 The title that appears on the custom button.
 */

@property (nonatomic, strong) NSString *title;

/**
 The object that recieves the target selector when the user selects the custom button.
 */

@property (nonatomic) NSObject *target;

/**
 The selector that should be called on the target when the user selects the custom button.
 */

@property (nonatomic) SEL selector;

@end
