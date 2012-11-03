//
//  Numbers.m
//  Numbers
//
//  Created by Yagita Hiroki on 12/11/03.
//  Copyright (c) 2012年 wiz-r. All rights reserved.
//

#import "Numbers.h"

#define kNumbersMaxSize 25


@interface NSMutableArray (Internal)
- (void)shuffle;
@end

@implementation NSMutableArray (Internal)

- (void)shuffle
{
  int max = [self count];
  for (int i = 0; i < max; i++) {
    int change = i + (rand() % max - i);
    
    NSNumber* n = [self objectAtIndex:i];
    [self replaceObjectAtIndex:i withObject:[self objectAtIndex:change]];
    [self replaceObjectAtIndex:change withObject:n];
  }
}

@end

@interface Numbers ()
@end

@implementation Numbers

- (id)init
{
  self = [super init];
  if (self) {
    self.numbers = [NSMutableArray arrayWithCapacity:kNumbersMaxSize];
    for (int i = 1; i <= kNumbersMaxSize; i++) {
      [self.numbers addObject:[NSNumber numberWithInt:i]];
    }
    
    srand(time(NULL));
    
    [self.numbers shuffle];
    
    self.targetNumber = 1;
  }
  return self;
}

@end
