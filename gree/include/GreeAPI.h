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


typedef void (^GreeAPIResponseBlock)(id object, NSError* error);


@protocol GreeAPIEnumerator <NSObject>

- (NSInteger)startIndex;
- (void)setStartIndex:(NSInteger)startIndex;
- (NSInteger)pageSize;
- (void)setPageSize:(NSInteger)pageSize;
- (BOOL)canLoadNext;
- (BOOL)canLoadPrevious;

- (void)loadNext:(GreeAPIResponseBlock)block;
- (void)loadPrevious:(GreeAPIResponseBlock)block;

@end

@protocol GreeAPIDefaultParameters <NSObject>
- (NSDictionary*)parameters;
- (void)setParameters:(NSDictionary*)parameters;
@optional
- (NSString*)languageCode;
- (void)setLanguageCode:(NSString*)languageCode;
@end

@protocol GreeAPI <NSObject>
@optional
+ (id<GreeAPIEnumerator>)getWithParameters:(NSDictionary*)parameters responseBlock:(GreeAPIResponseBlock)block;
+ (void)postWithParameters:(NSDictionary*)parameters responseBlock:(GreeAPIResponseBlock)block;
+ (void)putWithParameters:(NSDictionary*)parameters responseBlock:(GreeAPIResponseBlock)block;
+ (void)deleteWithParameters:(NSDictionary*)parameters responseBlock:(GreeAPIResponseBlock)block;
@end

@interface GreeAPIBase : NSObject <GreeAPI>
@end

extern NSString* const GreeAPIParameterKeyStartIndex;
extern NSString* const GreeAPIParameterKeyPageSize;
extern NSString* const GreeAPIParameterKeyHasMore;
extern NSString* const GreeAPIParameterKeyThumbnail;
extern NSString* const GreeAPIParameterKeyLanguageCode;
extern NSString* const GreeAPIParameterKeyUserIds;


