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

//#indoc "UIViewController+GreePlatform.h"

#import <UIKit/UIKit.h>
#import "GreeWidget.h"

@class GreePopup;

//#indoc "GreeNotificationBoardType"
typedef enum {
//#indoc "GreeNotificationBoardTypeGame"
  GreeNotificationBoardTypeGame,
//#indoc "GreeNotificationBoardTypeSNS"
  GreeNotificationBoardTypeSNS
} GreeNotificationBoardType;

//#indoc "GreeViewControllerType"
typedef enum {
  GreeViewControllerTypeSDK                       = 0x0000,
//#indoc "GreeViewControllerTypeDashboard"
  GreeViewControllerTypeDashboard                 = GreeViewControllerTypeSDK + 0,
//#indoc "GreeViewControllerTypeNotificationBoard"
  GreeViewControllerTypeNotificationBoard         = GreeViewControllerTypeSDK + 1,
//#indoc "GreeViewControllerTypeInvitePopup"
  GreeViewControllerTypeInvitePopup               = GreeViewControllerTypeSDK + 2,
//#indoc "GreeViewControllerTypeSharePopup"
  GreeViewControllerTypeSharePopup                = GreeViewControllerTypeSDK + 3,
//#indoc "GreeViewControllerTypeRequestPopup"
  GreeViewControllerTypeRequestPopup              = GreeViewControllerTypeSDK + 4,
//#indoc "GreeViewControllerTypeAuthorizationPopup"
  GreeViewControllerTypeAuthorizationPopup        = GreeViewControllerTypeSDK + 5,
//#indoc "GreeViewControllerTypeWalletPaymentPopup"
  GreeViewControllerTypeWalletPaymentPopup        = GreeViewControllerTypeSDK + 6,
//#indoc "GreeViewControllerTypeWalletDepositPopup"
  GreeViewControllerTypeWalletDepositPopup        = GreeViewControllerTypeSDK + 7,
//#indoc "GreeViewControllerTypeWalletDepositHistoryPopup"
  GreeViewControllerTypeWalletDepositHistoryPopup = GreeViewControllerTypeSDK + 8,
//#indoc "GreeViewControllerTypeOther"
  GreeViewControllerTypeOther                     = 0x1000,
} GreeViewControllerType;

//#indoc "UIViewController+GreePlatform"
@interface UIViewController (GreePlatform)

//#indoc "UIViewController+GreePlatform#presentGreeDashboardWithParameters"
- (void)presentGreeDashboardWithParameters:(NSDictionary*)parameters animated:(BOOL)animated;
//#indoc "UIViewController+GreePlatform#presentGreeNotificationBoardWithType"
- (void)presentGreeNotificationBoardWithType:(GreeNotificationBoardType)type animated:(BOOL)animated;
//#indoc "UIViewController+GreePlatform#dismissActiveGreeViewControllerAnimated"
- (void)dismissActiveGreeViewControllerAnimated:(BOOL)animated;

//#indoc "UIViewController+GreePlatform#showGreePopup"
- (void)showGreePopup:(GreePopup*)popup;
//#indoc "UIViewController+GreePlatform#dismissGreePopup"
- (void)dismissGreePopup;

//#indoc "UIViewController+GreePlatform#showGreeWidgetWithDataSource"
- (void)showGreeWidgetWithDataSource:(id<GreeWidgetDataSource>)dataSource;

//#indoc "UIViewController+GreePlatform#hideGreeWidget"
- (void)hideGreeWidget;
//#indoc "UIViewController+GreePlatform#activeGreeWidget"
- (GreeWidget*)activeGreeWidget;

@end
