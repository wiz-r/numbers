//
//  Numbers.h
//  Numbers
//
//  Created by Yagita Hiroki on 12/11/03.
//  Copyright (c) 2012年 wiz-r. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Numbers : NSObject
@property (retain, nonatomic) NSMutableArray* numbers;
@property (assign, nonatomic, readonly) NSInteger targetNumber;
@property (assign, nonatomic, readonly) NSTimeInterval elapsedTime;
@property (assign, nonatomic, readonly) BOOL finishedGame;

- (void)start;
- (void)next;

@end
