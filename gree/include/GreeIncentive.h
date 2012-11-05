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

//#indoc "GreeIncentive.h"
#import <Foundation/Foundation.h>
#import "GreeEnumerator.h"


typedef enum {
  GreeIncentiveNotDelivered,
  GreeIncentiveAlreadyDelivered,
} GreeIncentiveDelivered;

typedef enum {
	GreeIncentiveTypeRequest = 1,
	GreeIncentiveTypeInvite = 2	
} GreeIncentiveType;

//#indoc "GreeIncentive"
@interface GreeIncentive : NSObject

@property (nonatomic, readonly, retain) NSString *fromUserId;
@property (nonatomic, readonly, retain) NSString *toUserId;
@property (nonatomic, readonly, retain) NSDictionary *payloadDictionary;
@property (nonatomic, readonly) GreeIncentiveType incentiveType;
@property (nonatomic, readonly) GreeIncentiveDelivered delivered;


//#indoc "GreeIncentive#initWithDictionary:"
//- (id)initWithDictionary:(NSDictionary*)incentiveDictionary;
- (id)initWithType:(GreeIncentiveType)incentiveType payloadDictionary:(NSDictionary*)payloadDictionary;

//#indoc "GreeIncentive#postIncentiveToUsers:block:"
- (void)postIncentiveToUsers:(NSArray *)targetUserIds block:(void(^)(NSString* numberOfTargets, NSError* error))block;

//#indoc "GreeIncentive#loadUnprocessedIncentivesWithBlock:"
+ (id<GreeEnumerator>)loadUnprocessedIncentivesOfType:(GreeIncentiveType)payloadType withBlock:(void(^)(NSArray* incentives, NSError* error))block;

//#indoc "GreeIncentive#completeWithBlock:"
- (void)completeWithBlock:(void(^)(NSError* error))block;

@end
