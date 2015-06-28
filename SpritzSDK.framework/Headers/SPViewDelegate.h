/*
 *  SPViewDelegate.h
 *  Spritz View Delegate
 *  Copyright 2014 Spritz Inc. All rights reserved.
 */

@class SPBaseView;
@class SPSource;

/*
 Delegates of SPBaseView and SPControlView can implement the SPViewDelegate. Optional methods allow the delegate to respond to various events associated with the spritz control.
 */

@protocol SPViewDelegate <NSObject>

@optional

/**
 Informs the delegate that the Spritz control has finished spritzing the content.
 
 @param spritzView Spritz control informing the delegate.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param segmentPos Word segment index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didFinish:(NSInteger)charPos segmentPos:(NSInteger)segmentPos timePos:(NSInteger)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the Spritz control moved backward a number of sentences.
 
 @param spritzView Spritz control informing the delegate.
 @param numSentences Number of sentences the Spritz control moved forward.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param segmentPos Word segment index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didGoBackSentence:(NSInteger)numSentences charPos:(NSInteger)charPos segmentPos:(NSInteger)segmentPos timePos:(NSInteger)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the Spritz control moved forward a number of sentences.
 
 @param spritzView Spritz control informing the delegate.
 @param numSentences Number of sentences the Spritz control moved forward.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param segmentPos Word segment index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didGoForwardSentence:(NSInteger)numSentences charPos:(NSInteger)charPos segmentPos:(NSInteger)segmentPos timePos:(NSInteger)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the Spritz control has loaded content.
 
 @param spritzView Spritz control informing the delegate.
 @param source The SPSource object that has been loaded.
 */

- (void)spritzView:(SPBaseView*)spritzView didLoad:(SPSource*)source;

/**
 Informs the delegate that the Spritz control is paused.
 
 @param spritzView Spritz control informing the delegate.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param segmentPos Word segment index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didPause:(NSInteger)charPos segmentPos:(NSInteger)segmentPos timePos:(NSInteger)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the Spritz control received an error and was unable to spritz the requested content.
 
 @warning If this method is not implemented or no delegate is set, a UIAlertView containing the details of the error is presented to the user. If this delegate is set, the SDK makes no indication to the user that there was an error.
 
 @param spritzView The Spritz control informing the delegate.
 @param error Error that prevented the Spritz control from displaying the requested content.
 */

- (void)spritzView:(SPBaseView*)spritzView didReceiveError:(NSError*)error;

/**
 Informs the delegate that the Spritz control reset its content.
 
 @param spritzView Spritz control informing the delegate.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param segmentPos Word segment index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didReset:(NSInteger)charPos segmentPos:(NSInteger)segmentPos timePos:(NSInteger)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the Spritz control resumed spritzing text.
 
 @param spritzView Spritz control informing the delegate.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param segmentPos Word segment index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didResume:(NSInteger)charPos segmentPos:(NSInteger)segmentPos timePos:(NSInteger)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the Spritz control did seek to a different position.
 
 @param spritzView Spritz control informing the delegate.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param segmentPos Word segment index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didSeek:(NSInteger)charPos segmentPos:(NSInteger)segmentPos timePos:(NSInteger)timePos speed:(NSInteger)speed;

/**
 Informs the delegate that the Spritz control started spritzing text.
 
 @param spritzView Spritz control informing the delegate.
 @param source The SPSource object that has been loaded.
 @param charPos Character index of the first character of the currently displayed word in the overall string of text.
 @param segmentPos Word segment index of the currently displayed word in the overall string of text.
 @param timePos Time position of the currently displayed word at the currently set speed, measured in milliseconds.
 @param speed Current speed measured in words per minute (wpm).
 */

- (void)spritzView:(SPBaseView*)spritzView didStart:(NSInteger)charPos segmentPos:(NSInteger)segmentPos timePos:(NSInteger)timePos speed:(NSInteger)speed;

@end
