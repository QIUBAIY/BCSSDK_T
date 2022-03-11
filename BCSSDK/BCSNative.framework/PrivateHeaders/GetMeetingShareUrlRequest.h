//
//  GetMeetingShareUrlRequest.h
//  BCSNative
//
//  Created by butelmac on 2021/8/5.
//  Copyright © 2021 redcdn. All rights reserved.
//

#import <BCSNative/ConferenceSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface GetMeetingShareUrlRequest : BCSPostBaseDataAdaptor

- (NSInteger)GetMeetingShareUrlWithToken:(NSString *)token meetingID:(NSInteger)meetingID succeed:(void (^)(id))succeed failed:(void (^)(long, NSString *))failed;

@end

NS_ASSUME_NONNULL_END
