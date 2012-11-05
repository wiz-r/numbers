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

#import <UIKit/UIKit.h>

//#indoc "GreeWidget.h"

//#indoc "GreeWidgetPosition"
typedef enum {
//#indoc "GreeWidgetPositionTopLeft"
  GreeWidgetPositionTopLeft,
//#indoc "GreeWidgetPositionBottomLeft"
  GreeWidgetPositionBottomLeft,
//#indoc "GreeWidgetPositionMiddleLeft"
  GreeWidgetPositionMiddleLeft,
  
//#indoc "GreeWidgetPositionTopRight"
  GreeWidgetPositionTopRight,
//#indoc "GreeWidgetPositionBottomRight"
  GreeWidgetPositionBottomRight,
//#indoc "GreeWidgetPositionMiddleRight"
  GreeWidgetPositionMiddleRight,
} GreeWidgetPosition;

@class GreeWidget;

//#indoc "GreeWidgetDataSource"
@protocol GreeWidgetDataSource<NSObject>
@required
//#indoc "GreeWidgetDataSource#screenshotImageForWidget"
- (UIImage*)screenshotImageForWidget:(GreeWidget*)widget;

@optional
//#indoc "GreeWidgetDataSource#screenshotDescription"
- (NSString *)screenshotDescription;
@end

//#indoc "GreeWidget"
@interface GreeWidget : UIView

//#indoc "GreeWidget#position"
@property (nonatomic, readwrite, assign) GreeWidgetPosition position;

//#indoc "GreeWidget#expandable"
@property (nonatomic, readwrite, assign) BOOL expandable;

//#indoc "GreeWidget#dataSource"
@property (nonatomic, readwrite, assign) id<GreeWidgetDataSource> dataSource;

@end
