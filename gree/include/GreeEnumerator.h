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

//#indoc "GreeEnumerator.h"

#import <Foundation/Foundation.h>

//#indoc "GreeEnumeratorResponseBlock"
typedef void(^GreeEnumeratorResponseBlock)(NSArray* items, NSError* error);

//#indoc "GreeEnumerator"
@protocol GreeEnumerator <NSObject>

//#indoc "GreeEnumerator#startIndex"
- (NSInteger)startIndex;

//#indoc "GreeEnumerator#pageSize"
- (NSInteger)pageSize;

//#indoc "GreeEnumerator#canLoadPrevious"
- (BOOL)canLoadPrevious;

//#indoc "GreeEnumerator#canLoadNext"
- (BOOL)canLoadNext;

//#indoc "GreeEnumerator#loadNext"
- (void)loadNext:(GreeEnumeratorResponseBlock)block;

//#indoc "GreeEnumerator#loadPrevious"
- (void)loadPrevious:(GreeEnumeratorResponseBlock)block;

//#indoc "GreeEnumerator#setStartIndex"
- (void)setStartIndex:(NSInteger)startIndex;

//#indoc "GreeEnumerator#setPageSize"
- (void)setPageSize:(NSInteger)pageSize;

//#indoc "GreeEnumerator#setGuid"
- (void)setGuid:(NSString*)guid;

@end

//#indoc "GreeCountableEnumerator"
@protocol GreeCountableEnumerator <GreeEnumerator>

//#indoc "GreeCountableEnumerator#count"
- (NSInteger)count;

@end
