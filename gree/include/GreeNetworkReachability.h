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

//#indoc "GreeNetworkReachability.h"

#import <Foundation/Foundation.h>

//#indoc "GreeNetworkReachabilityStatus"
typedef enum {
//#indoc "GreeNetworkReachabilityUnknown"
	GreeNetworkReachabilityUnknown,
//#indoc "GreeNetworkReachabilityConnectedViaWiFi"
	GreeNetworkReachabilityConnectedViaWiFi,
//#indoc "GreeNetworkReachabilityConnectedViaCarrier"
	GreeNetworkReachabilityConnectedViaCarrier,
//#indoc "GreeNetworkReachabilityNotConnected"
	GreeNetworkReachabilityNotConnected,
} GreeNetworkReachabilityStatus;

//#indoc "NSStringFromGreeNetworkReachabilityStatus"
NSString* NSStringFromGreeNetworkReachabilityStatus(GreeNetworkReachabilityStatus status);

//#indoc "GreeNetworkReachabilityStatusIsConnected"
BOOL GreeNetworkReachabilityStatusIsConnected(GreeNetworkReachabilityStatus status);

typedef void(^GreeNetworkReachabilityChangedBlock)(GreeNetworkReachabilityStatus previous, GreeNetworkReachabilityStatus current);

//#indoc "GreeNetworkReachability"
@interface GreeNetworkReachability : NSObject

@property (nonatomic, readonly, retain) NSString* host;
@property (nonatomic, readonly, assign) GreeNetworkReachabilityStatus status;

//#indoc "GreeNetworkReachability#initWithHost"
- (id)initWithHost:(NSString*)host;

//#indoc "GreeNetworkReachability#addObserverBlock"
- (id)addObserverBlock:(GreeNetworkReachabilityChangedBlock)observer;

//#indoc "GreeNetworkReachability#removeObserverBlock"
- (void)removeObserverBlock:(id)handle;

//#indoc "GreeNetworkReachability#isConnectedToInternet"
- (BOOL)isConnectedToInternet;

@end
