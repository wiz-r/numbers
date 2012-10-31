//
//  GameViewController.m
//  Numbers
//
//  Created by hiroki-yagita on 12/10/29.
//  Copyright (c) 2012年 wiz-r. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import "GameViewController.h"


@interface Numbers : NSObject
@property (retain, nonatomic) NSMutableArray* numbers;
@property (assign, nonatomic) NSInteger targetNumber;
@end

@implementation Numbers

- (id)init
{
  self = [super init];
  if (self) {
    self.numbers = [NSMutableArray array];
    for (int i = 1; i <= 25; i++) {
      [self.numbers addObject:[NSNumber numberWithInt:i]];
    }
    
    srand(time(NULL));
    
    for (int i = 0; i < 25; i++) {
      int change = i + (rand() % 25 - i);
      
      NSNumber* n = [self.numbers objectAtIndex:i];
      [self.numbers replaceObjectAtIndex:i
                              withObject:[self.numbers objectAtIndex:change]];
      [self.numbers replaceObjectAtIndex:change
                              withObject:n];
    }
    
    self.targetNumber = 1;
  }
  return self;
}
@end



@interface GameViewController () <AVAudioSessionDelegate>
@property (retain, nonatomic) IBOutlet UIView *countDownView;
@property (retain, nonatomic) IBOutlet UILabel *countDownLabel;
@property (retain, nonatomic) IBOutletCollection(UIButton) NSArray *numberButtons;
@property (retain, nonatomic) IBOutlet UILabel *currentNumberLabel;
@property (retain, nonatomic) IBOutlet UILabel *currentTimeLabel;
@property (retain, nonatomic) IBOutlet UIView *containerView;

@property (assign, nonatomic) int count;
@property (retain, nonatomic) NSDate* startTime;
@property (retain, nonatomic) NSDate* currentTime;

@property (retain, nonatomic) Numbers* numbers;

@property (retain, nonatomic) AVAudioPlayer* player;

- (IBAction)numberButtonTapped:(id)sender;

- (void)finishGame;

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

  // setup count down view
  self.count = 3;
  [self.view addSubview:self.countDownView];
  [self countDown];
  
  // setup game model
  self.numbers = [[[Numbers alloc] init] autorelease];

  for (UIButton* button in self.numberButtons) {
    
  }
}

- (void)viewDidLoad
{
  [super viewDidLoad];
	// Do any additional setup after loading the view.
  
  AVAudioSession *audioSession = [AVAudioSession sharedInstance];
  [audioSession setCategory:AVAudioSessionCategoryAmbient error:nil];
  [audioSession setActive:YES error:nil];
  
  NSString *soundPath = [[NSBundle mainBundle] pathForResource:@"tap" ofType:@"wav"];
  NSURL *file = [[[NSURL alloc] initFileURLWithPath:soundPath] autorelease];
  self.player = [[[AVAudioPlayer alloc] initWithContentsOfURL:file error:nil] autorelease];
  [self.player prepareToPlay];
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
    self.numbers.targetNumber = self.numbers.targetNumber + 1;
    
    if (tappedNumber == 25) {
      [self finishGame];
    }
  }
}

- (void)finishGame
{
  [[[[UIAlertView alloc]
     initWithTitle:@"Congraturation!"
     message:@"やったね"
     delegate:nil
     cancelButtonTitle:nil
     otherButtonTitles:@"OK",
     nil] autorelease] show];
}

@end
