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


#import <Foundation/Foundation.h>
#import "GreeAPI.h"
#import "GreeSerializable.h"


@interface GreeMyApplication : NSObject <GreeAPI, GreeSerializable>
@property (nonatomic, retain, readonly) NSString* identifier;
@property (nonatomic, retain, readonly) NSString* name;
@property (nonatomic, retain, readonly) NSString* shortenName;
@property (nonatomic, retain, readonly) NSURL* thumbnailUrlSmall;
@property (nonatomic, retain, readonly) NSURL* thumbnailUrlMiddle;
@property (nonatomic, retain, readonly) NSURL* thumbnailUrlLarge;
@property (nonatomic, retain, readonly) NSDate* lastAccess;
@end

extern NSString* const GreeMyApplicationParameterDeviceKey;
extern NSString* const GreeMyApplicationParameterDeviceAll;
extern NSString* const GreeMyApplicationParameterDeviceFP;
extern NSString* const GreeMyApplicationParameterDeviceSP;
extern NSString* const GreeMyApplicationParameterDeviceIOS;
extern NSString* const GreeMyApplicationParameterDeviceAndroid;

