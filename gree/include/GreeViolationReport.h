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


enum {
  GreeViolationReportParameterCategoryIdDating        = 9000,
  GreeViolationReportParameterCategoryIdSexualContent = 9001,
  GreeViolationReportParameterCategoryIdViolationLow  = 9002,
  GreeViolationReportParameterCategoryIdProfit        = 9003,
  GreeViolationReportParameterCategoryIdDisturbance   = 9004,
  GreeViolationReportParameterCategoryIdOther         = 9005,
  GreeViolationReportParameterCategoryIdCheat         = 9006,
  GreeViolationReportParameterCategoryIdRMT           = 9007,
};


@interface GreeViolationReport : NSObject

@property (nonatomic, retain, readonly) NSString* reportId;
@property (nonatomic, retain, readonly) NSString* appId;
@property (nonatomic, retain, readonly) NSString* userId;
@property (nonatomic, retain, readonly) NSString* comment;
@property (nonatomic, retain, readonly) NSString* targetUserId;
@property (nonatomic, retain, readonly) NSString* textId;
@property (nonatomic, retain, readonly) NSDate* reportedTime;

+ (void)reportWithParameters:(NSDictionary*)parameters block:(void(^)(GreeViolationReport* report, NSError* error))block;

@end


extern const NSString* const GreeViolationReportParameterCategoryIdKey;
extern const NSString* const GreeViolationReportParameterCommentKey;
extern const NSString* const GreeViolationReportParameterTargetUserIdKey;
extern const NSString* const GreeViolationReportParameterTextIdKey;
