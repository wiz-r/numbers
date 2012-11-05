//
// Copyright 2011 GREE, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

//#indoc "GreeAchievement.h"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GreeWriteCacheable.h"
#import "GreeSerializable.h"
#import "GreeEnumerator.h"

//#indoc "GreeAchievement"
@interface GreeAchievement : NSObject<GreeWriteCacheable, GreeSerializable>

//#indoc "GreeAchievement#identifier"
@property (nonatomic, retain, readonly) NSString* identifier;
//#indoc "GreeAchievement#name"
@property (nonatomic, retain, readonly) NSString* name;
//#indoc "GreeAchievement#descriptionText"
@property (nonatomic, retain, readonly) NSString* descriptionText;
//#indoc "GreeAchievement#isSecret"
@property (nonatomic, assign, readonly) BOOL isSecret;
//#indoc "GreeAchievement#score"
@property (nonatomic, assign, readonly) NSInteger score;
//#indoc "GreeAchievement#isUnlocked"
@property (nonatomic, assign, readonly) BOOL isUnlocked;

//#indoc "GreeAchievement#initWithIdentifier"
- (id)initWithIdentifier:(NSString*)identifier;

//#indoc "GreeAchievement#loadAchievementsWithBlock"
+ (id<GreeEnumerator>)loadAchievementsWithBlock:(void(^)(NSArray* achievements, NSError* error))block;

//#indoc "GreeAchievement#loadIconWithBlock"
- (void)loadIconWithBlock:(void(^)(UIImage* image, NSError* error))block;

//#indoc "GreeAchievement#cancelIconLoad"
- (void)cancelIconLoad;

//#indoc "GreeAchievement#unlock"
- (void)unlockWithBlock:(void(^)(void))block;

//#indoc "GreeAchievement#relock"
- (void)relockWithBlock:(void(^)(void))block;

//#indoc "GreeAchievement#setGameCenterResponseBlock"
- (void)setGameCenterResponseBlock:(void(^)(NSError* error))responseBlock;

@end
