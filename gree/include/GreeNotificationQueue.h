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

//#indoc "GreeNotificationQueue.h"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GreeNotificationTypes.h"
#import "GreePlatform.h"
#import "GreePlatformComponent.h"

@class GreeNotification;
@class GreeSettings;

//#indoc "GreeNotificationQueue"
@interface GreeNotificationQueue : NSObject<UIGestureRecognizerDelegate, GreePlatformComponent>

//#indoc "GreeNotificationQueue#initWithSettings"
- (id)initWithSettings:(GreeSettings*)settings;

//#indoc "GreeNotificationQueue#displayPosition"
@property (nonatomic) GreeNotificationDisplayPosition displayPosition;

//#indoc "GreeNotificationQueue#notificationsEnabled"
@property BOOL notificationsEnabled;

//#indoc "GreeNotificationQueue#notification"
- (void)addNotification:(GreeNotification*)notification;

@end

@interface GreePlatform (GreeNotifications)
//#indoc "GreeNotificationQueue#GreePlatform::notificationQueue"
- (GreeNotificationQueue*)notificationQueue;
@end



