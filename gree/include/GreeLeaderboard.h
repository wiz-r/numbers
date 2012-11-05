//
// Copyright 2012 GREE, Inc.
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

//#indoc "GreeLeaderboard.h"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GreeSerializable.h"
#import "GreeEnumerator.h"

//#indoc "GreeLeaderboardSortOrder"
typedef enum {
//#indoc "GreeLeaderboardSortOrderDescending"
  GreeLeaderboardSortOrderDescending,
//#indoc "GreeLeaderboardSortOrderAscending"
  GreeLeaderboardSortOrderAscending,
} GreeLeaderboardSortOrder;

//#indoc "GreeLeaderboardFormat"
typedef enum {
//#indoc "GreeLeaderboardFormatInteger"
  GreeLeaderboardFormatInteger = 0,
//#indoc "GreeLeaderboardFormatTime"
  GreeLeaderboardFormatTime = 2,
} GreeLeaderboardFormat;

//#indoc "GreeLeaderboard"
@interface GreeLeaderboard : NSObject<GreeSerializable>

//#indoc "GreeLeaderboard#identifer"
@property (nonatomic, retain, readonly) NSString* identifier;
//#indoc "GreeLeaderboard#name"
@property (nonatomic, retain, readonly) NSString* name;
//#indoc "GreeLeaderboard#format"
@property (nonatomic, assign, readonly) GreeLeaderboardFormat format;
//#indoc "GreeLeaderboard#formatSuffix"
@property (nonatomic, retain, readonly) NSString* formatSuffix;
//#indoc "GreeLeaderboard#formatDecimal"
@property (nonatomic, assign, readonly) NSInteger formatDecimal;
//#indoc "GreeLeaderboard#timeFormat"
@property (nonatomic, retain, readonly) NSString* timeFormat;
//#indoc "GreeLeaderboard#sortOrder"
@property (nonatomic, assign, readonly) GreeLeaderboardSortOrder sortOrder;
//#indoc "GreeLeaderboard#allowWorseScore"
@property (nonatomic, assign, readonly) BOOL allowWorseScore;
//#indoc "GreeLeaderboard#isSecret"
@property (nonatomic, assign, readonly) BOOL isSecret;

//#indoc "GreeLeaderboard#loadLeaderboardWithBlock"
+ (id<GreeEnumerator>)loadLeaderboardsWithBlock:(void(^)(NSArray* leaderboards, NSError* error)) block;

//#indoc "GreeLeaderboard#loadIconWithBlock"
- (void)loadIconWithBlock:(void(^)(UIImage* image, NSError* error))block;

//#indoc "GreeLeaderboard#cancelIconLoad"
- (void)cancelIconLoad;

@end
