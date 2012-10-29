//
//  ViewController.m
//  Numbers
//
//  Created by hiroki-yagita on 12/10/29.
//  Copyright (c) 2012年 wiz-r. All rights reserved.
//

#import "GameViewController.h"
#import "ViewController.h"

@interface ViewController ()
- (IBAction)playButtonTouched:(id)sender;
- (IBAction)leaderboardButtonTouched:(id)sender;
- (IBAction)optionButtonTouched:(id)sender;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)playButtonTouched:(id)sender
{
  UIViewController* viewController = [[GameViewController alloc] init];
  [self presentViewController:viewController animated:NO completion:nil];
  [viewController release];
}

- (IBAction)leaderboardButtonTouched:(id)sender {
}

- (IBAction)optionButtonTouched:(id)sender {
}
@end
