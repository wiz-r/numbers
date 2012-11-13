//
//  GameViewController.m
//  Numbers
//
//  Created by hiroki-yagita on 12/10/29.
//  Copyright (c) 2012年 wiz-r. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import "GameViewController.h"
#import "Numbers.h"

#import "GreeScore.h"


static NSString* const myLeaderboardId = @"10001557";


@interface GameViewController () <AVAudioSessionDelegate>
@property (retain, nonatomic) IBOutletCollection(UIButton) NSArray* numberButtons;
@property (retain, nonatomic) IBOutlet UILabel* currentNumberLabel;
@property (retain, nonatomic) IBOutlet UILabel* currentTimeLabel;
@property (retain, nonatomic) IBOutlet UIView* containerView;
@property (retain, nonatomic) Numbers* numbers;
@property (retain, nonatomic) AVAudioPlayer* player;
- (IBAction)numberButtonTapped:(id)sender;
- (void)finishGame;
- (void)updateLabelForNextNumber;
@end

@implementation GameViewController

- (void)countUpTimer
{
  if (self.numbers.finishedGame) return;
  
  self.currentTimeLabel.text = [NSString stringWithFormat:@"%03.3f", self.numbers.elapsedTime];
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

  // setup game model
  self.numbers = [[[Numbers alloc] init] autorelease];

  for (NSUInteger i = 0; i < 25; i++) {
    UIButton* button = [self.numberButtons objectAtIndex:i];
    NSNumber* shuffledNumber = [self.numbers.numbers objectAtIndex:i];
    NSInteger n = [shuffledNumber integerValue];
    button.tag = n;
    NSString* imageName = [NSString stringWithFormat:@"numbers_button_off_p_%02d.png", n];
    UIImage* image = [UIImage imageNamed:imageName];
    [button setImage:image forState:UIControlStateNormal];
  }

  AVAudioSession *audioSession = [AVAudioSession sharedInstance];
  [audioSession setCategory:AVAudioSessionCategoryAmbient error:nil];
  [audioSession setActive:YES error:nil];
  
  NSString *soundPath = [[NSBundle mainBundle] pathForResource:@"tap" ofType:@"wav"];
  NSURL *file = [[[NSURL alloc] initFileURLWithPath:soundPath] autorelease];
  self.player = [[[AVAudioPlayer alloc] initWithContentsOfURL:file error:nil] autorelease];
  [self.player prepareToPlay];
  
  [self updateLabelForNextNumber];
}

- (void)viewDidAppear:(BOOL)animated
{
  [super viewDidAppear:animated];
  [self.numbers start];
  [self countUpTimer];
}

- (void)dealloc
{
  [_numberButtons release];
  [_currentNumberLabel release];
  [_currentTimeLabel release];
  [_containerView release];
  [_numbers release];
  [_player release];
  [super dealloc];
}

- (IBAction)numberButtonTapped:(id)sender
{
  NSLog(@"sender:%@", sender);

  UIButton* button = (UIButton*)sender;
  NSInteger tappedNumber = button.tag;
  
  [self.player play];
  
  if (self.numbers.targetNumber == tappedNumber) {
    NSString* imageName = [NSString stringWithFormat:@"numbers_button_on_p_%02d.png", tappedNumber];
    UIImage* image = [UIImage imageNamed:imageName];
    [button setImage:image forState:UIControlStateNormal];
    button.userInteractionEnabled = NO;

    [self.numbers next];

    if (self.numbers.finishedGame) {
      [self finishGame];
    } else {
      self.currentNumberLabel.text = [NSString stringWithFormat:@"> %d", self.numbers.targetNumber];
    }
  }
}

- (void)finishGame
{
  [[[[UIAlertView alloc]
     initWithTitle:@"Congratulation!"
     message:@"やったね"
     delegate:nil
     cancelButtonTitle:nil
     otherButtonTitles:@"OK",
     nil] autorelease] show];
  
  int64_t timeval = (int64_t)(self.numbers.elapsedTime * 1000);
  __block GreeScore* score = [[GreeScore alloc] initWithLeaderboard:myLeaderboardId score:timeval];
  [score submitWithBlock:^{
    NSLog(@"score submitted:%@", score);
    [score release];
  }];
}

- (void)updateLabelForNextNumber
{
  self.currentNumberLabel.text = [NSString stringWithFormat:@"> %d", self.numbers.targetNumber];
}


@end
