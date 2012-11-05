//
//  AppDelegate.m
//  Numbers
//
//  Created by hiroki-yagita on 12/10/29.
//  Copyright (c) 2012年 wiz-r. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import "Flurry.h"
#import "GreePlatform.h"
#import "GreePlatformSettings.h"


@interface AppDelegate () <GreePlatformDelegate>
@end

@implementation AppDelegate

- (void)dealloc
{
  [_window release];
  [_viewController release];
  [super dealloc];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  // Flurry
  [Flurry startSession:@"RY9PKZM4FRQM7K4HX7QH"];
  
  [GreePlatform
   printEncryptedStringWithConsumerKey:@"f78d7e7e17f3"
   consumerSecret:@"884df28891ed8a3822da1bfc7ca48306"
   scramble:@"ten1unko"];
  
  NSDictionary* settings = [NSDictionary dictionaryWithObjectsAndKeys:
                            GreeDevelopmentModeProduction, GreeSettingDevelopmentMode,
                            nil];
  
  [GreePlatform
   initializeWithApplicationId:@"58352"
   consumerKey:@"f78d7e7e17f3"
   consumerSecret:@"884df28891ed8a3822da1bfc7ca48306"
   settings:settings
   delegate:self];
  
  [GreePlatform handleLaunchOptions:launchOptions application:application];
  
  // App Initialization
  self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];
  // Override point for customization after application launch.
  self.viewController = [[[ViewController alloc] initWithNibName:@"ViewController" bundle:nil] autorelease];
  self.window.rootViewController = self.viewController;
  [self.window makeKeyAndVisible];
  
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
  [GreePlatform shutdown];
}

- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
{
  return [GreePlatform handleOpenURL:url application:application];
}

- (void)greePlatformWillShowModalView:(GreePlatform*)platform
{
  NSLog(@"greePlatformWillShowModalView");
}

- (void)greePlatformDidDismissModalView:(GreePlatform*)platform
{
  NSLog(@"greePlatformDidDismissModalView");
}

- (void)greePlatform:(GreePlatform*)platform didLoginUser:(GreeUser*)localUser
{
  NSLog(@"greePlatform:didLoginUser:%@", localUser);
}

- (void)greePlatform:(GreePlatform*)platform didLogoutUser:(GreeUser*)localUser
{
  NSLog(@"greePlatform:didLogoutUser:%@", localUser);
}

- (void)greePlatformParamsReceived:(NSDictionary*)params
{
  NSLog(@"greePlatformParamsReceived:%@", params);
}

- (void)greePlatform:(GreePlatform*)platform didUpdateLocalUser:(GreeUser*)localUser
{
  NSLog(@"greePlatform:didUpdateLocalUser:%@", localUser);
}

@end
