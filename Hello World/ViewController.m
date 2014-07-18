//
//  ViewController.m
//  Hello World
//
//  Created by Drew Ingebretsen on 4/10/14.
//  Copyright (c) 2014 Spritz. All rights reserved.
//

#import "ViewController.h"
#import <Spritz-SDK/SpritzSDK.h>
#import <UNIRest.h>

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UISegmentedControl *spritzStyleSegmentedControl;
@property (weak, nonatomic) IBOutlet SpritzInlineView *spritzInlineView;

@end

@implementation ViewController

-(id) init
{
    self = [super init];
    
    [super viewDidLoad];
    
    
    return self;
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
-(void)convertPDF
{
    
}
- (IBAction)startSpritz:(id)sender {
    if (self.spritzStyleSegmentedControl.selectedSegmentIndex == 0){
        
        NSString *reading = [[NSUserDefaults standardUserDefaults]objectForKey:@"reading"];
        
        //The SpritzInlineView class is a UIView subclass that can be inititated from a UIStoryboard. The startSpritzing method starts spritzing the passed in URL.
        NSBundle *bundle = [NSBundle mainBundle];
        NSString *textFilePath = [bundle pathForResource:@"Good" ofType:@"txt"];
        NSString *fileContents=[NSString stringWithContentsOfFile:textFilePath encoding:NSASCIIStringEncoding error:NULL];
        
        if (!reading)
        {
            reading = fileContents;
        }
        [self.spritzInlineView startSpritzing:reading sourceType:SourceFlagPlain];
    }
    else{
        if (self.spritzStyleSegmentedControl.selectedSegmentIndex == 1){
            
            //The SpritzViewController is self contained UIViewController that contains a SpritzInlineView and several utility controls. The startSpritzing method starts spritzing the passed in URL.
            
            SpritzViewController *spritzVC = [[SpritzViewController alloc] init];
            NSString *reading = [[NSUserDefaults standardUserDefaults]objectForKey:@"reading"];
            
            //The SpritzInlineView class is a UIView subclass that can be inititated from a UIStoryboard. The startSpritzing method starts spritzing the passed in URL.
            NSBundle *bundle = [NSBundle mainBundle];
            NSString *textFilePath = [bundle pathForResource:@"Good" ofType:@"txt"];
            NSString *fileContents=[NSString stringWithContentsOfFile:textFilePath encoding:NSASCIIStringEncoding error:NULL];
            
            if (!reading)
            {
                reading = fileContents;
            }
            
            [self presentViewController:spritzVC animated:YES completion:^{
                [spritzVC startSpritzing:reading sourceType:SourceFlagPlain];
                
            
            }];
        }
    }
}

@end
