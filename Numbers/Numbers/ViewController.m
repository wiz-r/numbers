//
//  ViewController.m
//  Numbers
//
//  Created by hiroki-yagita on 12/10/29.
//  Copyright (c) 2012年 wiz-r. All rights reserved.
//

#import "CountDownViewController.h"
#import "ViewController.h"

@interface ViewController ()
- (IBAction)playButtonTouched:(id)sender;
- (IBAction)leaderboardButtonTouched:(id)sender;
- (IBAction)optionButtonTouched:(id)sender;
@end

@implementation ViewController

- (IBAction)playButtonTouched:(id)sender
{
  UIViewController* viewController = [[[CountDownViewController alloc] init] autorelease];
  [self presentViewController:viewController animated:NO completion:nil];
}

- (IBAction)leaderboardButtonTouched:(id)sender
{
}

- (IBAction)optionButtonTouched:(id)sender
{
}

@end
