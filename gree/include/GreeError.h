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

//#indoc "GreeError.h"

#import <Foundation/Foundation.h>

//#indoc "GreeErrorDomain"
extern NSString* GreeErrorDomain;

enum {
//#indoc "GreeErrorCodeNetworkError"
  GreeErrorCodeNetworkError = 1000,
//#indoc "GreeErrorCodeBadDataFromServer"
  GreeErrorCodeBadDataFromServer = 1010,
//#indoc "GreeErrorCodeNotAuthorized"
  GreeErrorCodeNotAuthorized = 1020,
//#indoc "GreeErrorCodeUserRequired"
  GreeErrorCodeUserRequired = 1030,
  
//#indoc "GreeErrorCodeAuthorizationFailWithOffline"
  GreeErrorCodeAuthorizationFailWithOffline = 1040, 
//#indoc "GreeErrorCodeAuthorizationCancelledByUser"
  GreeErrorCodeAuthorizationCancelledByUser = 1050,
//#indoc "GreeErrorCodeLogoutCancelledByUser"
  GreeErrorCodeLogoutCancelledByUser = 1060,
  
//#indoc "GreeWalletPaymentErrorCodeUnknown"
  GreeWalletPaymentErrorCodeUnknown  = 2000,
//#indoc "GreeWalletPaymentErrorCodeInvalidParameter"
  GreeWalletPaymentErrorCodeInvalidParameter  = 2010,
//#indoc "GreeWalletPaymentErrorCodeUserCanceled"
  GreeWalletPaymentErrorCodeUserCanceled  = 2020,
//#indoc "GreeWalletPaymentErrorCodeTransactionExpired"
  GreeWalletPaymentErrorCodeTransactionExpired  = 2030,
//#indoc "GreeWalletPaymentErrorCodeTransactionAlreadyInProgress"
  GreeWalletPaymentErrorCodeTransactionAlreadyInProgress  = 2040,
  
//#indoc "GreeWalletDepositErrorCodeFailedTransactionCommit"
  GreeWalletDepositErrorCodeFailedTransactionCommit = 3000,
//#indoc "GreeWalletDepositErrorCodeTransactionAlreadyInProgress"
  GreeWalletDepositErrorCodeTransactionAlreadyInProgress = 3010,
//#indoc "GreeWalletDepositErrorCodeProductListNotReady"
  GreeWalletDepositErrorCodeProductListNotReady = 3020,
//#indoc "GreeWalletDepositErrorCodeProductMetadataInvalid"
  GreeWalletDepositErrorCodeProductMetadataInvalid = 3021,
  
//#indoc "GreeWalletDepositErrorCodeSKProductDataInvalid"
  GreeWalletDepositErrorCodeSKProductDataInvalid = 3022,

//#indoc "GreeWalletDepositErrorCodePriceListDataInvalid"
  GreeWalletDepositErrorCodePriceListDataInvalid = 3023,
  
//#indoc "GreeWalletDepositErrorCodeSKProductListEmpty"
  GreeWalletDepositErrorCodeSKProductListEmpty = 3024,
  
//#indoc "GreeWalletDepositErrorCodeMergedProductListEmpty"
  GreeWalletDepositErrorCodeMergedProductListEmpty = 3025,
  
//#indoc "GreeWalletDepositErrorCodeResourceListEmpty"
  GreeWalletDepositErrorCodeResourceListEmpty = 3026,
  
//#indoc "GreeWalletDepositErrorCodeResourceDownloadError"
  GreeWalletDepositErrorCodeResourceDownloadError = 3027,
  
//#indoc "GreeWalletDepositUserStatusError"
  GreeWalletDepositUserStatusError = 3030,
  
//#indoc "GreeWalletBalanceErrorCodeTransactionAlreadyInProgress"
  GreeWalletBalanceErrorCodeTransactionAlreadyInProgress  = 3100,
  
//#indoc "GreeWalletPurchaseErrorCodeUnknownProductId"
  GreeWalletPurchaseErrorCodeInvalidProductId  = 3200,
//#indoc "GreeWalletPurchaseErrorCodeUserCancelled"
  GreeWalletPurchaseErrorCodeUserCancelled = 3210,
  
//#indoc "GreeFriendCodeAlreadyRegistered"
  GreeFriendCodeAlreadyRegistered = 4000,
//#indoc "GreeFriendCodeAlreadyEntered"
  GreeFriendCodeAlreadyEntered = 4010,
//#indoc "GreeFriendCodeNotFound"
  GreeFriendCodeNotFound = 4020,
  
  GreeAPINotAllowed = 5000,

  GreeAddressBookNoRecordInDevice = 6000,
  GreeAddressBookNoNeedUpload = 6010,

  GreeExternalSocialGraphUpdateInvalidParameter = 7000,
  GreeExternalSocialGraphUpdateAccessDenied = 7010,
  GreeExternalSocialGraphUpdateOperationFailed = 7020,

  GreeSocialGraphInvalidParameter = 8000,

//#indoc "GreeIncentiveSubmitFailed"
	GreeIncentiveSubmitFailed = 5000,
  
  GreeErrorCodeReservedBase = 100000,
};

