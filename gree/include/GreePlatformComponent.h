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

@class GreeSettings;
@class GreeUser;

//#indoc "GreePlatformComponent"
@protocol GreePlatformComponent <NSObject>
@required

//#indoc "GreePlatformComponent#componentWithSettings"
+ (id)componentWithSettings:(GreeSettings *)settings;

@optional
//#indoc "GreePlatformComponent#handleRemoteNotification"
- (void)handleRemoteNotification:(NSDictionary *)notificationDictionary;

//#indoc "GreePlatformComponent#willRemoveComponentFromPlatform"
- (void)willRemoveComponentFromPlatform;

//#indoc "GreePlatformComponent#userLoggedIn"
- (void)userLoggedIn:(GreeUser*)user;

//#indoc "GreePlatformComponent#userLoggedOut"
- (void)userLoggedOut:(GreeUser*)user;
@end
