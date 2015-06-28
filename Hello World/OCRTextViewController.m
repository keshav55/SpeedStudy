#import "OCRTextViewController.h"
#import <QuartzCore/QuartzCore.h>
#import <SpritzSDK/SpritzSDK.h>
#import "ViewController.h"

@implementation OCRTextViewController




- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
	self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
	
	if (self != nil) {
		self.title = NSLocalizedString(@"Text", @"Text");
	}
	
	return self;
}

- (void)configureView
{	
	if (self.text != nil) {
	    self.textView.text = self.text;
	}
}

- (void)viewDidLoad
{
	[super viewDidLoad];
	[self configureView];
}

#pragma mark -

- (void)setText:(NSString *)text
{
    if (_text != text) {
		_text = text;
        [[NSUserDefaults standardUserDefaults]setObject:text forKey:@"reading"];
        [self configureView];
    }
}
-(void)goAway {
    
   
    
    
}
@end
