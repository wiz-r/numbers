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
//#indoc "GreeWalletPaymentItem.h"

#import <Foundation/Foundation.h>
#import "GreeSerializable.h"

//#indoc "GreeWalletPaymentItem" 1
@interface GreeWalletPaymentItem : NSObject<GreeSerializable>

//#indoc "GreeWalletPaymentItem#itemId" 1
@property (nonatomic, copy) NSString*	itemId;
//#indoc "GreeWalletPaymentItem#itemName" 1
@property (nonatomic, copy) NSString*	itemName;
//#indoc "GreeWalletPaymentItem#unitPrice" 1
@property (nonatomic)	NSUInteger	unitPrice;
//#indoc "GreeWalletPaymentItem#quantity" 1
@property (nonatomic)	NSUInteger	quantity;
//#indoc "GreeWalletPaymentItem#imageUrl" 1
@property (nonatomic, copy)	NSString*	imageUrl;
//#indoc "GreeWalletPaymentItem#description" 1
@property (nonatomic, copy) NSString* description;

//#indoc "GreeWalletPaymentItem#paymentItemWithItemId:itemName:unitPrice:quantity:imageUrl:description:" 1
+ (GreeWalletPaymentItem*)paymentItemWithItemId:(NSString*)itemId 
    itemName:(NSString*)itemName 
    unitPrice:(NSUInteger)unitPrice
    quantity:(NSUInteger)quantity
    imageUrl:(NSString*)imageUrl
    description:(NSString*)description;

//#indoc "GreeWalletPaymentItem#descriptionString" 1
- (NSString*)descriptionString;

@end
