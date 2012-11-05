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

//#indoc "GreeUser.h"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GreeSerializable.h"
#import "GreeEnumerator.h"

//#indoc "GreeUserThumbnailSize"
typedef enum {
//#indoc "GreeUserThumbnailSizeSmall"
  GreeUserThumbnailSizeSmall,
//#indoc "GreeUserThumbnailSizeStandard"
  GreeUserThumbnailSizeStandard,
//#indoc "GreeUserThumbnailSizeLarge"
  GreeUserThumbnailSizeLarge,
//#indoc "GreeUserThumbnailSizeHuge"
  GreeUserThumbnailSizeHuge
} GreeUserThumbnailSize;

//#indoc "GreeUserGrade"
typedef enum {
//#indoc "UserGradeLite"
  GreeUserGradeLite = 1,
//#indoc "UserGradeLimited"
  GreeUserGradeLimited = 2,
//#indoc "UserGradeStandard"
  GreeUserGradeStandard = 3
} GreeUserGrade;

//#indoc "GreeUser"
@interface GreeUser : NSObject<GreeSerializable>
//#indoc "GreeUser#userId"
@property(nonatomic, readonly, retain) NSString* userId;
//#indoc "GreeUser#nickname"
@property(nonatomic, readonly, retain) NSString* nickname;
//#indoc "GreeUser#userGrade"
@property(nonatomic, readonly, assign) GreeUserGrade userGrade;
//#indoc "GreeUser#aboutMe"
@property(nonatomic, readonly, retain) NSString* aboutMe;
//#indoc "GreeUser#birthday"
@property(nonatomic, readonly, retain) NSString* birthday;
//#indoc "GreeUser#gender"
@property(nonatomic, readonly, retain) NSString* gender;
//#indoc "GreeUser#age"
@property(nonatomic, readonly, retain) NSString* age;
//#indoc "GreeUser#bloodType"
@property(nonatomic, readonly, retain) NSString* bloodType;
//#indoc "GreeUser#region"
@property(nonatomic, readonly, retain) NSString* region;
//#indoc "GreeUser#subRegion"
@property(nonatomic, readonly, retain) NSString* subRegion;
//#indoc "GreeUser#language"
@property(nonatomic, readonly, retain) NSString* language;
//#indoc "GreeUser#timeZone"
@property(nonatomic, readonly, retain) NSString* timeZone;
//#indoc "GreeUser#displayName"
@property(nonatomic, readonly, retain) NSString* displayName;
//#indoc "GreeUser#profileUrl"
@property(nonatomic, readonly, retain) NSURL* profileUrl;
//#indoc "GreeUser#userHash"
@property(nonatomic, readonly, retain) NSString* userHash;
//#indoc "GreeUser#userType"
@property(nonatomic, readonly, retain) NSString* userType;
//#indoc "GreeUser#thumbnailUrl"
@property(nonatomic, readonly, retain) NSURL* thumbnailUrl;
//#indoc "GreeUser#thumbnailUrlSmall"
@property(nonatomic, readonly, retain) NSURL* thumbnailUrlSmall;
//#indoc "GreeUser#thumbnailUrlLarge"
@property(nonatomic, readonly, retain) NSURL* thumbnailUrlLarge;
//#indoc "GreeUser#thumbnailUrlHuge"
@property(nonatomic, readonly, retain) NSURL* thumbnailUrlHuge;

//#indoc "GreeUser#loadUserWithId:block:"
+ (void)loadUserWithId:(NSString*)userId block:(void(^)(GreeUser* user, NSError* error))block;

//#indoc "GreeUser#loadFriendsWithBlock"
- (id<GreeCountableEnumerator>)loadFriendsWithBlock:(void(^)(NSArray* friends, NSError* error))block;

//#indoc "GreeUser#loadIgnoredUserIdsWithBlock"
- (id<GreeEnumerator>)loadIgnoredUserIdsWithBlock:(void(^)(NSArray* ignoredUserIds, NSError* error))block;

//#indoc "Greeuser#loadThumbnailImageWithSize:block:"
- (void)loadThumbnailWithSize:(GreeUserThumbnailSize)size block:(void(^)(UIImage* icon, NSError* error))block;

//#indoc "Greeuser#cancelThumbnailLoad"
- (void)cancelThumbnailLoad;

//#indoc "GreeUser#isIgnoringUserWithId:block:"
- (void)isIgnoringUserWithId:(NSString*)ignoredUserId block:(void(^)(BOOL isIgnored, NSError* error))block;

//#indoc "GreeUser#hasThisApplication"
- (BOOL)hasThisApplication;

@end
