/*
 *  SPBaseView.h
 *  Spritz Base View
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import "SPViewDelegate.h"
#import "SPSource.h"

/**
 SPBaseView is the base Spritz control. It provides a basic Spritz redicle, with no spritzing controls associated with the view. The SPBaseView will prompt the user to login with their Spritz account, or create one, before they can Spritz content.
 */

@interface SPBaseView : UIView

/**
 Character index of the first character of the currently displayed word in the overall string of text. (read-only)
 */

@property (nonatomic, readonly) NSInteger characterPosition;

/**
 The delegate receives events associated with the user's spritzing actions (such as start, stop, pause, and so on).
 */

@property (nonatomic, weak) IBOutlet id<SPViewDelegate> delegate;

/**
 Returns YES if the Spritz control currently has text loaded. (read-only)
 */

@property (nonatomic, readonly) BOOL loaded;

/**
 Returns YES if the Spritz control is currently loading text. (read-only)
 */

@property (nonatomic, readonly) BOOL loading;

/**
 Returns YES if the Spritz control is currently paused. Return NO if there is no content loaded.
 */

@property (nonatomic, readonly) BOOL paused;

/**
 Returns the progress of the currently loaded stream of text. Measured from 0.0f-1.0f;
 */

@property (nonatomic, readonly) CGFloat progress;

/**
 Returns the count of the word segments of the currently loaded stream of text. (read-only)
 @warning segmentCount is not syncrhonized with word count from the orignal text string due to the way Spritz processes text. There usually will be more word segments than there are words.
 */

@property (nonatomic, readonly) NSInteger segmentCount;

/**
Returns the segment index of the currently displayed word segment in the overall string of text. (read-only)
@warning segmentPosition is not syncrhonized with the word index from the orignal text string due to the way Spritz processes text. There usually will be more word segments than there are words.
 */

@property (nonatomic, readonly) NSInteger segmentPosition;

/**
 Current speed measured in words per minute (wpm). Can be set at anytime and updates the view in real time.
 */

@property (nonatomic, assign) NSInteger speed;

/**
 Max. possible speed for the current user.
 */

@property (nonatomic, readonly) NSUInteger speedLimit;

/**
 Returns YES if the Spritz control has been started by the user. (read-only)
 */

@property (nonatomic, readonly) BOOL started;

/**
 *  Determines if the ramp-up sweeper animation should be shown. Can be set at any time and updates the view in real time. Defaults to YES.
 */

@property (nonatomic, assign) BOOL sweeper;

/**
 The text content currently loaded into the Spritz control.
 */

@property (nonatomic, readonly) NSString *text;

/**
 The color of the text in the reticle.
 */

@property (nonatomic, strong) IBInspectable UIColor *textColor;

/**
 The color of the highlighted text in the reticle.
 */

@property (nonatomic, strong) IBInspectable UIColor *textHighlightColor;

/**
 Returns the time position of the currently displayed word at the currently set speed, measured in milliseconds. (read-only)
 */

@property (nonatomic, readonly) NSInteger timePosition;

/**
 Starts spritzing the specified source to the Spritz control.
 
 @param source Source of the text.
 
 */

/**
 The color of the Spritz reticle lines.
 */

@property (nonatomic, strong) IBInspectable UIColor *reticleLineColor;


- (void)start:(SPSource *)source;

/**
 Starts spritzing the specified text to the Spritz control with the specified speed.
 
 @param source Source of the text.
 @param speed Speed at which to spritz the text, in words per minute. (wpm)
 */

- (void)start:(SPSource *)source speed:(NSInteger)speed;

/**
 Starts spritzing the specified text to the Spritz control with the specified speed and position.
 
 @param source Source of the text.
 @param speed Speed at which to spritz the text, in words per minute. (wpm)
 @param characterPosition Position at which to start spritzing, specified by character index.
 */

- (void)start:(SPSource *)source speed:(NSInteger)speed characterPosition:(NSInteger)characterPosition;

/**
 Resets the spritz control, clears all content and resets to the default state.
 
 @warning Resetting the Spritz control does not reset the speed.
 */

- (void)reset;

/**
 Loads the specified source object and puts the Spritz control into a paused state.
 */

- (void)load:(SPSource*)source;

/**
 Pauses the Spritz control if the control is currently spritzing text.
 */

- (void)pause;

/**
 Resumes the Spritz control if the control is currently in a paused state.
 */

- (void)resume;

/**
 Toggles the Spritz control between paused and playing states.
 */

- (void)togglePause;

/**
 Returns to the beginning of the current sentence or one sentence past the current sentence if the current word is located at the beginning of a sentence.
 
 @warning Calling this method pauses the Spritz control automatically.
 */

- (void)goBackSentence;

/**
 Goes back the specified number of sentences. If the current word is not at the beginning of a sentence, the current sentence is counted as one sentence.
 
 @warning Calling this method pauses the Spritz control automatically.
 @param numberOfSentences number of sentences to move back.
 */

- (void)goBackSentences:(NSInteger)numberOfSentences;

/**
 Moves forward to the next sentence.
 
 @warning Calling this method pauses the Spritz control automatically.
 */

- (void)goForwardSentence;

/**
 Moves forward the number of sentences specified.
 
 @warning Calling this method pauses the Spritz control automatically.
 @param numberOfSentences number of sentences to move forward.
 */

- (void)goForwardSentences:(NSInteger)numberOfSentences;

/**
 Seeks to the specified word segment.
 
 @param position index of the word to seek to.
 @param absolute If set to YES, the control seeks to the specified index in the overall text. If set to NO, the control seeks to the word relative to the current word segment index.
 */

- (void)seekToSegment:(NSInteger)position absolute:(BOOL)absolute;

/**
 Seeks to the specified character.
 
 @param position index of the character to seek to.
 @param absolute If set to YES, the control seeks to the specified index in the overall text. If set to NO, the control seeks to the character relative to the current character index.
 */

- (void)seekToCharacter:(NSInteger)position absolute:(BOOL)absolute;

@end