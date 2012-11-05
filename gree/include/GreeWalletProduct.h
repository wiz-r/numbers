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

//#indoc "GreeWalletProduct.h"

#import <UIKit/UIKit.h>

////#indoc "GreeWalletProduct"
@interface GreeWalletProduct : NSObject

//#indoc "GreeWalletProduct#productId"
@property(nonatomic, readonly)NSString* productId;

//#indoc "GreeWalletProduct#productTitle"
@property(nonatomic, readonly)NSString* productTitle;

//#indoc "GreeWalletProduct#productDescription"
@property(nonatomic, readonly)NSString* productDescription;

//#indoc "GreeWalletProduct#currencyCode"
@property(nonatomic, readonly)NSString* currencyCode;

//#indoc "GreeWalletProduct#price"
@property(nonatomic, readonly)NSString* price;

//#indoc "GreeWalletProduct#iconURL"
@property(nonatomic, readonly)NSString* iconURL;

//#indoc "GreeWalletProduct#tier"
@property(nonatomic, readonly)NSString* tier;

//#indoc "GreeWalletProduct#totalAmount"
@property(nonatomic, readonly)NSString* totalAmount;

//#indoc "GreeWalletProduct#points"
@property(nonatomic, readonly)NSString* points;

//#indoc "GreeWalletProduct#isAvailable"
@property(nonatomic, readonly)BOOL isAvailable;

//#indoc "GreeWalletProduct#loadIconWithBlock:"
- (void)loadIconWithBlock:(void(^)(UIImage* image, NSError* error))block;

//#indoc "GreeWalletProduct#cancelIconLoad"
- (void)cancelIconLoad;

@end
