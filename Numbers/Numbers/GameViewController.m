//
//  GameViewController.m
//  Numbers
//
//  Created by hiroki-yagita on 12/10/29.
//  Copyright (c) 2012年 wiz-r. All rights reserved.
//

#import "GameViewController.h"

@interface GameViewController ()
@property (retain, nonatomic) IBOutlet UIView *countDownView;
@property (retain, nonatomic) IBOutlet UILabel *countDownLabel;
@property (retain, nonatomic) IBOutletCollection(UIButton) NSArray *numberButtons;
@property (retain, nonatomic) IBOutlet UILabel *currentNumberLabel;
@property (retain, nonatomic) IBOutlet UILabel *currentTimeLabel;
@property (retain, nonatomic) IBOutlet UIView *containerView;


@property (assign, nonatomic) int count;
@property (retain, nonatomic) NSDate* startTime;
@property (retain, nonatomic) NSDate* currentTime;

@end

@implementation GameViewController

- (void)countDown
{
  self.countDownLabel.text = [NSString stringWithFormat:@"%d", self.count];
  
  if (0 < self.count) {
    [self performSelector:@selector(countDown) withObject:nil afterDelay:1.0];
  } else {
    [self.countDownView removeFromSuperview];
    
    // ゲーム開始タイマースタート
    self.startTime = [NSDate date];
    self.currentTime = [NSDate date];
    [self countUpTimer];
  }

  self.count = self.count - 1;
}

- (void)countUpTimer
{
  self.currentTime = [NSDate date];
  NSTimeInterval diff = [self.currentTime timeIntervalSinceDate:self.startTime];
  self.currentTimeLabel.text = [NSString stringWithFormat:@"%03.3f", diff];
  [self performSelector:@selector(countUpTimer) withObject:nil afterDelay:0.01f];
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewWillAppear:(BOOL)animated
{
  [super viewWillAppear:animated];
  
  self.count = 3;
  
  [self.view addSubview:self.countDownView];
  [self countDown];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc {
  [_countDownView release];
  [_numberButtons release];
  [_countDownLabel release];
  [_currentNumberLabel release];
  [_currentTimeLabel release];
  [_containerView release];
  [super dealloc];
}
@end
