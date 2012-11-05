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

#import "UIKit/UIKit.h"
#import "GreeEnumerator.h"

//#indoc "GreeFriendCodes.h"

//#indoc "GreeFriendCodes"
@interface GreeFriendCodes : NSObject
//#indoc "GreeFriendCodes:requestCodeWithBlock"
+ (void)requestCodeWithBlock:(void(^)(NSString* code, NSError* error)) block;

//#indoc "GreeFriendCodes:requestCodeWithExpirationDate"
+ (void)requestCodeWithExpirationDate:(NSDate*) expirationDate block:(void(^)(NSString* code, NSError* error)) block;

//#indoc "GreeFriendCodes:verifyCode"
+ (void)verifyCode:(NSString*)code withBlock:(void(^)(NSError* error)) block;

//#indoc "GreeFriendCodes:loadFriendCodeWithBlock"
+ (void)loadCodeWithBlock:(void(^)(NSString* code, NSDate* expiration, NSError* error)) block;

//#indoc "GreeFriendCodes:loadFriendsWithBlock"
+ (id<GreeEnumerator>)loadFriendsWithBlock:(void(^)(NSArray* friends, NSError* error)) block;

//#indoc "GreeFriendCodes:getCodeOwner"
+ (void)loadCodeOwner:(void(^)(NSString* userId, NSError* error)) block;

//#indoc "GreeFriendCodes:deleteCodeWithBlock"
+ (void)deleteCodeWithBlock:(void(^)(NSError* error)) block;

@end
