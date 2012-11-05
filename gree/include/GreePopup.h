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

//#indoc "GreePopupFileHeader" 1

#import <UIKit/UIKit.h>
#import "GreeIncentive.h"

//#indoc "GreePopupWillLaunchNotification" 1
extern NSString* const GreePopupWillLaunchNotification;
//#indoc "GreePopupDidLaunchNotification" 1
extern NSString* const GreePopupDidLaunchNotification;
//#indoc "GreePopupWillDismissNotification" 1
extern NSString* const GreePopupWillDismissNotification;
//#indoc "GreePopupDidDismissNotification" 1
extern NSString* const GreePopupDidDismissNotification;

//#indoc "GreePopupInviteAction" 1
extern NSString* const GreePopupInviteAction;
//#indoc "GreePopupShareAction" 1
extern NSString* const GreePopupShareAction;
//#indoc "GreePopupRequestServiceAction" 1
extern NSString* const GreePopupRequestServiceAction;

//#indoc "GreeRequestServicePopupTitle" 1
extern NSString* const GreeRequestServicePopupTitle;
//#indoc "GreeRequestServicePopupBody" 1
extern NSString* const GreeRequestServicePopupBody;
//#indoc "GreeRequestServicePopupMobileImage" 1
extern NSString* const GreeRequestServicePopupMobileImage;
//#indoc "GreeRequestServicePopupImageURL" 1
extern NSString* const GreeRequestServicePopupImageURL;
//#indoc "GreeRequestServicePopupMobileURL" 1
extern NSString* const GreeRequestServicePopupMobileURL;
//#indoc "GreeRequestServicePopupRedirectURL" 1
extern NSString* const GreeRequestServicePopupRedirectURL;
//#indoc "GreeRequestServicePopupAttributes" 1
extern NSString* const GreeRequestServicePopupAttributes;
//#indoc "GreeRequestServicePopupCallbackURL" 1
extern NSString* const GreeRequestServicePopupCallbackURL;
//#indoc "GreeRequestServicePopupListType" 1
extern NSString* const GreeRequestServicePopupListType;
//#indoc "GreeRequestServicePopupToUserId" 1
extern NSString* const GreeRequestServicePopupToUserId;
//#indoc "GreeRequestServicePopupExpireTime" 1
extern NSString* const GreeRequestServicePopupExpireTime;

//#indoc "GreeRequestServicePopupListTypeAll" 1
extern NSString* const GreeRequestServicePopupListTypeAll;
//#indoc "GreeRequestServicePopupListTypeJoined" 1
extern NSString* const GreeRequestServicePopupListTypeJoined;
//#indoc "GreeRequestServicePopupListTypeNotJoined" 1
extern NSString* const GreeRequestServicePopupListTypeNotJoined;
//#indoc "GreeRequestServicePopupListTypeSpecified" 1
extern NSString* const GreeRequestServicePopupListTypeSpecified;

@class GreePopupView;
@class GreePopup;

//#indoc "GreePopupBlock" 1
typedef void (^GreePopupBlock)(GreePopup* aSender);

//#indoc "GreePopup" 1
@interface GreePopup : UIViewController
//#indoc "GreePopup#action" 1
@property (copy) NSString *action;
//#indoc "GreePopup#parameters" 1
@property (retain) NSDictionary *parameters;
//#indoc "GreePopup#results" 1
@property (retain) NSDictionary *results;
//#indoc "GreePopup#cancelBlock" 1
@property (copy) GreePopupBlock cancelBlock;
//#indoc "GreePopup#successBlock" 1
@property (copy) GreePopupBlock completeBlock;
//#indoc "GreePopup#willLaunchBlock" 1
@property (copy) GreePopupBlock willLaunchBlock;
//#indoc "GreePopup#didLaunchBlock" 1
@property (copy) GreePopupBlock didLaunchBlock;
//#indoc "GreePopup#willDismissBlock" 1
@property (copy) GreePopupBlock willDismissBlock;
//#indoc "GreePopup#didDismissBlock" 1
@property (copy) GreePopupBlock didDismissBlock;
//#indoc "GreePopup#popupView" 1
@property (nonatomic, readonly) GreePopupView *popupView;

//#indoc "GreePopup#hostViewController" 1
@property (nonatomic, assign) UIViewController *hostViewController;

//#indoc "GreePopup#initWithParameters:" 1
-(id)initWithParameters:(NSDictionary *)parameters;
//#indoc "GreePopup#popup" 1
+(id)popup;
//#indoc "GreePopup#popupWithParameters:" 1
+(id)popupWithParameters:(NSDictionary *)parameters;
//#indoc "GreePopup#show" 1
-(void)show;
//#indoc "GreePopup#dismiss" 1
-(void)dismiss;

//#indoc "GreePopup#loadRequest:" 1
-(void)loadRequest:(NSURLRequest *)aRequest;

//#indoc "GreePopup#loadData:MIMEType:textEncodingName:baseURL:" 1
-(void)loadData:(NSData *)aData MIMEType:(NSString *)aMIMEType textEncodingName:(NSString *)anEncodingName baseURL:(NSURL *)aBaseURL;

//#indoc "GreePopup#loadHTMLString:baseURL:" 1
-(void)loadHTMLString:(NSString *)aString baseURL:(NSURL *)aBaseURL;

//#indoc "GreePopup#stringByEvaluatingJavaScriptFromString:" 1
-(NSString *)stringByEvaluatingJavaScriptFromString:(NSString *)aScript;


//#indoc "GreePopup#jsonEncodeAttributes:" 1
+ (NSString*)jsonEncodeAttributes:(NSDictionary*)attributesDictionary;

@end

//#indoc "GreeInvitePopup" 1
@interface GreeInvitePopup : GreePopup
@property (copy) NSString* message;
@property (retain) NSURL* callbackURL;
@property (retain) NSArray* toUserIds;
@property	(retain) GreeIncentive *incentivePayload;
@end

//#indoc "GreeSharePopup" 1
@interface GreeSharePopup : GreePopup
@property (copy) NSString *text;
@property (retain) UIImage *attachingImage;
@property (copy) NSString *imageUrls;
@end

//#indoc "GreeRequestServicePopup" 1
@interface GreeRequestServicePopup : GreePopup
@property	(retain) GreeIncentive *incentivePayload;
@end
