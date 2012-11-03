//
//  CountDownViewController.m
//  Numbers
//
//  Created by Yagita Hiroki on 12/11/03.
//  Copyright (c) 2012年 wiz-r. All rights reserved.
//

#import "CountDownViewController.h"
#import "GameViewController.h"

@interface CountDownViewController ()
@property (retain, nonatomic) IBOutlet UILabel *countDownLabel;
@property (assign, nonatomic) int count;
- (void)countDown;
@end

@implementation CountDownViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)dealloc
{
  [_countDownLabel release];
  [super dealloc];
}

- (void)viewWillAppear:(BOOL)animated
{
  [super viewWillAppear:animated];

  self.count = 3;
  [self countDown];
}

- (void)countDown
{
  self.countDownLabel.text = [NSString stringWithFormat:@"%d", self.count];
  
  if (0 < self.count) {
    [self performSelector:@selector(countDown) withObject:nil afterDelay:1.0];
  } else {
    UIViewController* viewController = [[[GameViewController alloc] init] autorelease];
    [self presentViewController:viewController animated:NO completion:nil];
  }
  
  self.count = self.count - 1;
}


@end

