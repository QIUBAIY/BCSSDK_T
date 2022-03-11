//
//  MeetingManageParser.h
//  AFNetworking iOS Example
//
//  Created by dshy1234 on 15/4/20.
//  Copyright (c) 2015年 Gowalla. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface MeetingParser : NSObject{
    int rc;
    NSString *rd;
    NSDictionary *body;
}
- (int)getHeaderValue;

- (NSString *)getHeaderText;

- (NSDictionary *)getBody;

- (void)parse:(id)content;

- (Boolean)isOk;
@end
