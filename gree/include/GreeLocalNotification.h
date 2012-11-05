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

//#indoc "GreeLocalNotification.h"

#import <Foundation/Foundation.h>
#import <UIKit/UILocalNotification.h>
#import <UIKit/UIKit.h>
#import "GreePlatform.h"

extern NSString * const GreeLocalNotificationDidReceiveNotification;

@class GreeSettings;

//#indoc "GreeLocalNotification"
@interface GreeLocalNotification : NSObject
//#indoc "GreeLocalNotification#initWithSettings"
- (id)initWithSettings:(GreeSettings*)settings;
//#indoc "GreeLocalNotification#registerLocalNotificationWithDictionary"
- (BOOL)registerLocalNotificationWithDictionary:(NSDictionary *)aDictionary;
//#indoc "GreeLocalNotification#cancelNotification"
- (BOOL)cancelNotification:(NSNumber *)identifier;
//#indoc "GreeLocalNotification#localNotificationsEnabled"
@property BOOL localNotificationsEnabled;

@end

@interface GreePlatform (GreeLocalNotification)
//#indoc "GreeLocalNotification#GreePlatform::localNotification"
- (GreeLocalNotification*)localNotification;
@end
