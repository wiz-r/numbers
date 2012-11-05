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

//#indoc "GreeNotificationTypes.h"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//#indoc "GreeNotificationDisplayPosition"
typedef enum {
  //#indoc "GreeNotificationDisplayBottomPosition"
  GreeNotificationDisplayBottomPosition,
//#indoc "GreeNotificationDisplayTopPosition"
  GreeNotificationDisplayTopPosition
} GreeNotificationDisplayPosition;

//#indoc "NSStringFromGreeNotificationDisplayPosition"
NSString* NSStringFromGreeNotificationDisplayPosition(GreeNotificationDisplayPosition position);

//#indoc "NSStringFromInterfaceOrientation"
NSString* NSStringFromInterfaceOrientation(UIInterfaceOrientation interfaceOrientation);


//#indoc "GreeNotificationViewDisplayType"
typedef enum {
//#indoc "GreeNotificationViewDisplayDefaultType"
  GreeNotificationViewDisplayDefaultType,  
//#indoc "GreeNotificationViewDisplayCloseType"
  GreeNotificationViewDisplayCloseType
} GreeNotificationViewDisplayType;

//#indoc "NSStringFromGreeNotificationViewDisplayType"
NSString* NSStringFromGreeNotificationViewDisplayType(GreeNotificationViewDisplayType type);

//#indoc "GreeNotificationInfiniteDuration"
extern NSTimeInterval const GreeNotificationInfiniteDuration;
