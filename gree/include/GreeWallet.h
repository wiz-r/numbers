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
//#indoc "GreeWallet.h"

#import <UIKit/UIKit.h>

#import "GreePlatformComponent.h"

#import "GreeWalletPaymentItem.h"

//#indoc "GreeWalletDelegate" 1
@protocol GreeWalletDelegate <NSObject>
@optional
//#indoc "GreeWalletDelegate#walletDepositDidLaunchPopup" 1
- (void)walletDepositDidLaunchPopup;
//#indoc "GreeWalletDelegate#walletDepositDidDismissPopup" 1
- (void)walletDepositDidDismissPopup;
//#indoc "GreeWalletDelegate#walletDepositDidLaunchHistoryPopup" 1
- (void)walletDepositDidLaunchHistoryPopup;
//#indoc "GreeWalletDelegate#walletDepositDidDismissHistoryPopup" 1
- (void)walletDepositDidDismissHistoryPopup;
//#indoc "GreeWalletDelegate#walletPaymentDidLaunchPopup" 1
- (void)walletPaymentDidLaunchPopup;
//#indoc "GreeWalletDelegate#walletPaymentDidDismissPopup" 1
- (void)walletPaymentDidDismissPopup;
@end

//#indoc "GreeWallet" 1
@interface GreeWallet : NSObject <GreePlatformComponent>
//#indoc "GreeWallet#setDelegate"
+(void)setDelegate:(id<GreeWalletDelegate>)delegate;

//#indoc "GreeWallet#launchDepositPopup"
+ (void)launchDepositPopup;
//#indoc "GreeWallet#launchDepositHistoryPopup"
+ (void)launchDepositHistoryPopup;

//#indoc "GreeWallet#paymentWithItems:message:callbackUrl:successBlock:failureBlock:" 1
+ (void)paymentWithItems:(NSMutableArray*)items
    message:(NSString*)message
    callbackUrl:(NSString*)callbackUrl
    successBlock:(void(^)(NSString* paymentId, NSArray* items))successBlock
    failureBlock:(void(^)(NSString* paymentId, NSArray* items, NSError* error))failureBlock;

//#indoc "GreeWallet#paymentVerifyWithPaymentId:successBlock:failureBlock:" 1
+ (void)paymentVerifyWithPaymentId:(NSString*)paymentId
    successBlock:(void(^)(NSString* paymentId, NSArray* items))successBlock
    failureBlock:(void(^)(NSString* paymentId, NSArray* items, NSError* error))failureBlock;

@end
