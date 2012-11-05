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

//#indoc "GreeModeratedText.h"


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GreeSerializable.h"


//#indoc "GreeModerationStatus"
typedef enum {
//#indoc "GreeModerationStatusBeingChecked"
  GreeModerationStatusBeingChecked,
//#indoc "GreeModerationStatusResultApproved"
  GreeModerationStatusResultApproved,
//#indoc "GreeModerationStatusDeleted"
  GreeModerationStatusDeleted,
//#indoc "GreeModerationStatusResultRejected"
  GreeModerationStatusResultRejected
} GreeModerationStatus;

//#indoc "GreeModeratedTextUpdateNotification"
extern NSString* const GreeModeratedTextUpdatedNotification;

//#indoc "GreeModeratedText"
@interface GreeModeratedText : NSObject<GreeSerializable>

//#indoc "GreeModeratedText#textId"
@property(nonatomic, retain, readonly) NSString* textId;
//#indoc "GreeModeratedText#appId"
@property(nonatomic, retain, readonly) NSString* appId;
//#indoc "GreeModeratedText#authorId"
@property(nonatomic, retain, readonly) NSString* authorId;
//#indoc "GreeModeratedText#data"
@property(nonatomic, retain, readonly) NSString* content;

//#indoc "GreeModeratedText#status"
@property(nonatomic, assign, readonly) GreeModerationStatus status;

//#indoc "GreeModeratedText#createWithString"
+ (void)createWithString:(NSString*)string block:(void(^)(GreeModeratedText* createdUserText, NSError* error))block;

//#indoc "GreeModeratedText#loadFromIds"
+ (void)loadFromIds:(NSArray*)ids block:(void(^)(NSArray* userTexts, NSError* error))block;

//#indoc "GreeModeratedText#updateWithString"
- (void)updateWithString:(NSString*)updatedString block:(void(^)(NSError* error))block;

//#indoc "GreeModeratedText#deleteWithBlock"
- (void)deleteWithBlock:(void(^)(NSError* error))block;

//#indoc "GreeModeratedText#beginNotification"
- (void)beginNotification;

//#indoc "GreeModeratedText#endNotification"
- (void)endNotification;

//#indoc "GreeModeratedText#currentList"
+ (NSArray*)currentList;
@end
