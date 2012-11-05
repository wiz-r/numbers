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

//#indoc "GreeNotification.h"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GreeNotificationTypes.h"

//#indoc "GreeNotification"
@interface GreeNotification : NSObject

//#indoc "GreeNotification#message"
@property (nonatomic, copy, readonly) NSString* message;
//#indoc "GreeNotification#displayType"
@property (readonly) GreeNotificationViewDisplayType displayType;
//#indoc "GreeNotification#duration"
@property (readonly) NSTimeInterval duration;

//#indoc "GreeNotification#initWithMessage"
- (id)initWithMessage:(NSString*)message 
  displayType:(GreeNotificationViewDisplayType)displayType
  duration:(NSTimeInterval)duration;

@end
