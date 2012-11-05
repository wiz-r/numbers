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

//#indoc "GreeSerializable.h"

#import <Foundation/Foundation.h>

@class GreeSerializer;

//#indoc "GreeSerializable"
@protocol GreeSerializable<NSObject>
@required

//#indoc "GreeSerializable#initWithGreeSerializer"
- (id)initWithGreeSerializer:(GreeSerializer*)serializer;

//#indoc "GreeSerializable#serializeWithGreeSerializer"
- (void)serializeWithGreeSerializer:(GreeSerializer*)serializer;

@end
