//
//  AppDelegate.m
//  Hello World
//
//  Created by Drew Ingebretsen on 4/10/14.
//  Copyright (c) 2014 Spritz. All rights reserved.
//

#import "AppDelegate.h"
#import <Spritz-SDK/SpritzSDK.h>
#import "OCRMainViewController.h"

@implementation AppDelegate

static NSString *kClientID =  @"4524122930975538943";
static NSString *kClientSecret = @"b029cb59-efb7-4236-8367-11bd3e9f8ed1";

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [SpritzSDK setClientID:kClientID clientSecret:kClientSecret redirecURI:@"https://sdk.spritzinc.com/js/1.0/examples/login_success.html"];
    
//    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    
//	UIViewController *mainViewController = [[OCRMainViewController alloc] initWithNibName:@"MainView" bundle:nil];
	
//	self.navigationController = [[UINavigationController alloc] initWithRootViewController:mainViewController];
	
//	self.window.rootViewController = self.navigationController;
//    [self.window makeKeyAndVisible];
    
    return YES;
}
							
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
