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


#import <Foundation/Foundation.h>
#import "GreeAPI.h"
#import "GreeSerializable.h"


enum {
  GreeExternalSocialGraphTokenTypeFacebook,
};


@interface GreeExternalSocialGraph : NSObject <GreeAPI, GreeSerializable>

@property (nonatomic, retain, readonly) NSMutableArray* facebookFriends;
@property (nonatomic, retain, readonly) NSMutableArray* addressbookFriends;
@property (nonatomic, retain, readonly) NSMutableArray* greeFriends;

@end

extern NSString* const GreeExternalSocialGraphParameterKeyToken;
extern NSString* const GreeExternalSocialGraphParameterKeyType;
extern NSString* const GreeExternalSocialGraphParameterKeyServiceType;
extern NSString* const GreeExternalSocialGraphParameterServiceTypeFacebook;
extern NSString* const GreeExternalSocialGraphParameterServiceTypeGreeFriends;
extern NSString* const GreeExternalSocialGraphParameterServiceTypeAddressBook;


