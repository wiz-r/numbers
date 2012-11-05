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

//#indoc "GreeScore.h"

#import <Foundation/Foundation.h>
#import "GreeWriteCacheable.h"
#import "GreeSerializable.h"
#import "GreeEnumerator.h"

@class GreeUser;
@class GreeLeaderboard;

//#indoc "GreeScoreUnranked"
extern int64_t GreeScoreUnranked;

//#indoc "GreeScoreTimePeriod"
typedef enum {
//#indoc "GreeScoreTimePeriodDaily"
  GreeScoreTimePeriodDaily,
//#indoc "GreeScoreTimePeriodWeekly"
  GreeScoreTimePeriodWeekly,
//#indoc "GreeScoreTimePeriodAlltime"
  GreeScoreTimePeriodAlltime,
} GreeScoreTimePeriod;

//#indoc "GreePeopleScope"
typedef enum {
//#indoc "GreePeopleScopeSelf"
  GreePeopleScopeSelf,
//#indoc "GreePeopleScopeFriends"
  GreePeopleScopeFriends,
//#indoc "GreePeopleScopeAll"
  GreePeopleScopeAll,
} GreePeopleScope;

//#indoc "GreeScore"
@interface GreeScore : NSObject<GreeWriteCacheable, GreeSerializable>

//#indoc "GreeScore#user"
@property (nonatomic, retain, readonly) GreeUser* user;
//#indoc "GreeScore#score"
@property (nonatomic, assign, readonly) int64_t score;
//#indoc "GreeScore#leaderboardId"
@property (nonatomic, retain, readonly) NSString* leaderboardId;
//#indoc "GreeScore#rank"
@property (nonatomic, assign, readonly) int64_t rank;

//#indoc "GreeScore#initWithLeaderboard"
- (id)initWithLeaderboard:(NSString*)leaderboardId score:(int64_t)score;

//#indoc "GreeScore#loadMyScoreForLeaderboard"
+ (void)loadMyScoreForLeaderboard:(NSString*)leaderboardId 
  timePeriod:(GreeScoreTimePeriod)timePeriod 
  block:(void(^)(GreeScore* score, NSError* error))block;

//#indoc "GreeScore#loadTopScoresForLeaderboard"
+ (id<GreeEnumerator>)loadTopScoresForLeaderboard:(NSString*)leaderboardId 
  timePeriod:(GreeScoreTimePeriod)timePeriod 
  block:(void(^)(NSArray* scoreList, NSError* error))block;

//#indoc "GreeScore#loadTopFriendScoresForLeaderboard"
+ (id<GreeEnumerator>)loadTopFriendScoresForLeaderboard:(NSString*)leaderboardId 
  timePeriod:(GreeScoreTimePeriod)timePeriod 
  block:(void(^)(NSArray* scoreList, NSError* error))block;

//#indoc "GreeScore#scoreEnumeratorForLeaderboard"
+ (id<GreeEnumerator>)scoreEnumeratorForLeaderboard:(NSString*)leaderboardId 
  timePeriod:(GreeScoreTimePeriod)timePeriod 
  peopleScope:(GreePeopleScope)peopleScope;

//#indoc "GreeScore#submit"
- (void)submitWithBlock:(void(^)(void))block;

//#indoc "GreeScore#deleteMyScoreForLeaderboard"
+ (void)deleteMyScoreForLeaderboard:(NSString*)leaderboardId withBlock:(void(^)(NSError*error))block;

//#indoc "GreeScore#setGameCenterResponseBlock"
- (void)setGameCenterResponseBlock:(void(^)(NSError*))responseBlock;

//#indoc "GreeScore#formattedScoreWithLeaderboard"
- (NSString*)formattedScoreWithLeaderboard:(GreeLeaderboard*)leaderboard;

@end
