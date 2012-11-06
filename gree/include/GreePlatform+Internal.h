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

#import "GreePlatform.h"
#import "GreeUser.h"

@class GreeLogger;
@class GreeSettings;
@class GreeWriteCache;
@class GreeNetworkReachability;
@class GreeUserTextInspectionList;
@class GreeAnalyticsEvent;
@class GreeAuthorization;
@class GreePhoneNumberBasedController;
@class GreeBadgeValues;
@class GreeJSModalNavigationController;
@class GreePopup;
@class GreeRotator;
@class GreeBenchmark;
@protocol GreePlatformComponent;

typedef enum {
  GreePlatformRegistrationFlowDefault,
  GreePlatformRegistrationFlow3rdPartyUISupport,
  GreePlatformRegistrationFlowPhoneNumberBased
} GreePlatformRegistrationFlow;

@interface GreePlatform (Internal)

- (GreeLogger*)logger;
- (GreeSettings*)settings;
- (GreeWriteCache*)writeCache;
- (GreeNetworkReachability*)analyticsReachability;

/*
 *@return the application version number padded out to the format 0000.00.00
 *@note this method caches the version internally
 */
+ (NSString*)paddedAppVersion;

//return the raw bundleVersion
+ (NSString*)bundleVersion;

/*
 * @brief add an analytics event to the queue
 *
 * Adds a new analytics event to the queue of events
 * @param event A new analytics event
 * 
 */
- (void)addAnalyticsEvent:(GreeAnalyticsEvent*)event;

/*
 * @brief send the analytics to the analytics server and empty the queue
 *
 * Sends all of the analytics data to the server and empties the queue of locally stored events
 * @param block A callback block to execute when the network response is received
 * 
 */
- (void)flushAnalyticsQueueWithBlock:(void(^)(NSError* error))block;

/*
 * @brief Refresh the value of the badge for application and post a notification to other views
 *
 * @param block A block to execute after the badge updated.
 * @param forAllApplications If YES refresh the value of the badge for all applications.
 */
- (void)updateBadgeValuesWithBlock:(void(^)(GreeBadgeValues* badgeValues))block forAllApplications:(BOOL)forAllApplications;

/*
 * @brief notify launch parameters to Application
 */
- (void)notifyLaunchParameterToApp:(NSDictionary*)param;

/*
 * @brief Register a component class
 * @param klass The component class 
 */
+ (void)registerComponentClass:(Class<GreePlatformComponent>)klass;

+ (void)beginGeneratingRotation;
+ (void)endGeneratingRotation;

// return the dictionary object contains the GreeViewControllerType value
+ (NSMutableDictionary*)dictionaryWithTypeForViewController:(UIViewController*)aViewController;


@property (nonatomic, retain, readonly) GreeHTTPClient* httpClient;
@property (nonatomic, retain, readonly) GreeHTTPClient* httpsClient;
@property (nonatomic, retain, readonly) GreeHTTPClient* httpClientForApi;
@property (nonatomic, retain, readonly) GreeHTTPClient* httpsClientForApi;
@property (nonatomic, retain, readonly) id moderationList;
@property (nonatomic, retain, readonly) NSMutableDictionary *components;
@property (nonatomic, retain, readonly) GreeAuthorization* authorization;
@property (nonatomic, retain, readonly) GreePhoneNumberBasedController* phoneNumberBasedController;
@property (nonatomic, assign, readonly) id<GreePlatformDelegate> delegate;
@property (nonatomic, retain, readonly) GreeBadgeValues* badgeValues;
@property (nonatomic, assign, readonly) UIInterfaceOrientation interfaceOrientation;
@property NSUInteger deviceNotificationCount;
@property (nonatomic, retain) GreeRotator *rotator;
@property (nonatomic, assign) BOOL manuallyRotate;
@property (nonatomic, retain) GreeBenchmark* benchmark;
@property (nonatomic, assign, readonly) GreePlatformRegistrationFlow registrationFlow;

@end

@interface GreePlatform(NonInteractive)
/*
 * Start the authorization process non-interactively, allowing
 * 3rd party developers to implement their own login screen, using grade 1.
 *
 * DEPRECATED: use authorizeWithBlock: and set the GreeSettingRegistrationFlow setting
 * to GreeSettingRegistrationFlow3rdPartyUI.
 */
+ (void)authorizeNonInteractivelyWithBlock:(void(^)(GreeUser* localUser, NSError* error))block;

/*
 * Start the authorization process non-interactively, allowing
 * 3rd party developers to implement their own login screen, using a specified grade.
 *
 * DEPRECATED: use authorizeWithBlock: and set the GreeSettingRegistrationFlow setting
 * to GreeSettingRegistrationFlow3rdPartyUI.
 */
+ (void)authorizeNonInteractivelyWithBlock:(void(^)(GreeUser* localUser, NSError* error))block forGrade:(GreeUserGrade)targetGrade;

/**
 * Remove any authorization token, effectively logging out the user, without showing
 * a confirmation dialog (3rd-party developers can call their own confirmation dialog
 * before calling this).
 *
 * DEPRECATED: use revokeAuthorizationWithBlock: and set the GreeSettingRegistrationFlow setting
 * to GreeSettingRegistrationFlow3rdPartyUI.
 */
+ (void)revokeAuthorizationNonInteractivelyWithBlock:(void(^)(NSError* error))block;

/**
 * Check if a login screen is needed, or if it can be skipped and authorizeNonInteractivelyWithBlock
 * called directly.
 *
 * YES if the client application should display a login screen.
 */
+ (BOOL)shouldPresentAuthorizationView;
@end

@interface GreePlatform(RegisterAPI)
/**
 * Register a nickname.
 */
+ (void)registerNickName:(NSString*)nickName block:(void(^)(NSError* error))block;
@end

@protocol GreePlatformDelegateInternal <NSObject>
@optional
- (void)greePlatformInitializationCompleted;
- (void)greePlatformInitializationFailedWithError:(NSError*)error;
@end

#ifdef __clang__
  #define AUTORELEASEPOOL @autoreleasepool
#else
  #define AUTORELEASEPOOL for (NSAutoreleasePool* $pool = [[NSAutoreleasePool alloc] init]; $pool; [$pool drain], $pool = nil)
#endif

#define GREEPLATFORM_AUTOREGISTER_COMPONENT \
	+ (void)load \
	{ \
		AUTORELEASEPOOL { \
			[GreePlatform registerComponentClass:self]; \
		} \
	}

#define GREE_SAFE_RELEASE(_OBJECT) [_OBJECT release]; _OBJECT = nil;
