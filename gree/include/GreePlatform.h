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

//#indoc "GreePlatform.h"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GreeWidget.h"
#import "GreeBadgeValues.h"
#import "GreeDeprecation.h"

@class GreePlatform;
@class GreeUser;
@class GreeHTTPClient;
@class GreeWidget;
@class GreeNetworkReachability;

extern NSString* const GreeHTTPResponseMessageKey;

//#indoc "GreePlatformDelegate"
@protocol GreePlatformDelegate <NSObject>
@required
//#indoc "GreePlatformDelegate#greePlatformWillShowModalView"
- (void)greePlatformWillShowModalView:(GreePlatform*)platform;
//#indoc "GreePlatformDelegate#greePlatformDidDismissModalView"
- (void)greePlatformDidDismissModalView:(GreePlatform*)platform;
//#indoc "GreePlatformDelegate#greePlatform:didLoginUser:"
- (void)greePlatform:(GreePlatform*)platform didLoginUser:(GreeUser*)localUser;
//#indoc "GreePlatformDelegate#greePlatform:didLogoutUser:"
- (void)greePlatform:(GreePlatform*)platform didLogoutUser:(GreeUser*)localUser;
//#indoc "GreePlatformDelegate#greePlatformParamsReceived"
- (void)greePlatformParamsReceived:(NSDictionary*)params;
@optional
//#indoc "GreePlatformDelegate#greePlatform:didUpdateLocalUser:"
- (void)greePlatform:(GreePlatform*)platform didUpdateLocalUser:(GreeUser*)localUser;
@end

//#indoc "GreePlatform"
@interface GreePlatform : NSObject

//#indoc "GreePlatform#initialize"
+ (void)initializeWithApplicationId:(NSString*)applicationId 
  consumerKey:(NSString*)consumerKey 
  consumerSecret:(NSString*)consumerSecret 
  settings:(NSDictionary*)settings
  delegate:(id<GreePlatformDelegate>)delegate;

//#indoc "GreePlatform#shutdown"
+ (void)shutdown;

//#indoc "GreePlatform#sharedInstance"
+ (GreePlatform*)sharedInstance;

//#indoc "GreePlatform#version"
+ (NSString*)version;

//#indoc "GreePlatform#build"
+ (NSString*)build;

//#indoc "GreePlatform#authorizeWithBlock"
+ (void)authorizeWithBlock:(void(^)(GreeUser* localUser, NSError* error))block;

//#indoc "GreePlatform#revokeAuthorizationWithBlock"
+ (void)revokeAuthorizationWithBlock:(void(^)(NSError* error))block;

//#indoc "GreePlatform#isAuthorized"
+ (BOOL)isAuthorized;

//#indoc "GreePlatform#upgradeWithParams"
+ (void)upgradeWithParams:(NSDictionary*)params
  successBlock:(void(^)(void))successBlock
  failureBlock:(void(^)(void))failureBlock;

//#indoc "GreePlatform#accessToken"
- (NSString*)accessToken;

//#indoc "GreePlatform#accessTokenSecret"
- (NSString*)accessTokenSecret;

//#indoc "GreePlatform#printEncryptedStringWithConsumerKey"
+ (void)printEncryptedStringWithConsumerKey:(NSString*)consumerKey
    consumerSecret:(NSString*)consumerSecret
    scramble:(NSString*)scramble;

//#indoc "GreePlatform#setConsumerProtectionWithScramble"
+ (void)setConsumerProtectionWithScramble:(NSString*)scramble;

//#indoc "GreePlatform#setInterfaceOrientation"
+ (void)setInterfaceOrientation:(UIInterfaceOrientation)orientation;

//#indoc "GreePlatform#handleOpenURL"
+ (BOOL)handleOpenURL:(NSURL*)url application:(UIApplication*)application;

//#indoc "GreePlatform#signRequest"
- (void)signRequest:(NSMutableURLRequest*)request parameters:(NSDictionary*)params;

//#indoc "GreePlatform#greeApplicationURLScheme"
+ (NSString*)greeApplicationURLScheme;

//#indoc "GreePlatform#localUser"
@property (nonatomic, retain, readonly) GreeUser* localUser;

//#indoc "GreePlatform#localUserId"
@property (nonatomic, copy, readonly) NSString* localUserId;

//#indoc "GreePlatform#postDeviceToken"
+ (void)postDeviceToken:(NSData*)deviceToken block:(void(^)(NSError* error))block;

//#indoc "GreePlatform#handleRemoteNotification"
+ (BOOL)handleRemoteNotification:(NSDictionary *)notificationDictionary application:(UIApplication*)application;

//#indoc "GreePlatform#handleLocalNotification"
+ (void)handleLocalNotification:(UILocalNotification *)notification application:(UIApplication*)application;

//#indoc "GreePlatform#handleLaunchOptions"
+ (void)handleLaunchOptions:(NSDictionary*)launchOptions application:(UIApplication*)application;

//#indoc "GreePlatform#updateBadgeValuesWithBlock"
- (void)updateBadgeValuesWithBlock:(void(^)(GreeBadgeValues *badgeValues))block;

//#indoc "GreePlatform#badgeValues"
@property (nonatomic, retain, readonly) GreeBadgeValues *badgeValues;

//#indoc "GreePlatform#reachability"
- (GreeNetworkReachability*)reachability;

//#indoc "GreePlatform#showNoConnectionModelessAlert"
- (void)showNoConnectionModelessAlert;

@end


//#indoc "GreePlatform#Deprecated"
@interface GreePlatform(Deprecated)

//#indoc "GreePlatform#authorize"
+ (void)authorize GREEPLATFORM_DEPRECATED;

//#indoc "GreePlatform#revokeAuthorization"
+ (void)revokeAuthorization GREEPLATFORM_DEPRECATED;  

@end
