//
//  OEMConferConfigManager.h
//  ConferenceSDK
//
//  Created by butelmac on 2021/9/18.
//  Copyright © 2021 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>
#define OEMCONMANAGER  [OEMConferConfigManager sharedManager]
#define OEMCON_LFK(key) [OEMCONMANAGER textForKey:key]

NS_ASSUME_NONNULL_BEGIN

@interface OEMConferConfigManager : NSObject

+ (instancetype)sharedManager;

@property (nonatomic, copy) NSDictionary *languageDic;//外部传入的语言包

- (void)removeAllConfig;

- (void)setKeyValueOEMContant:(NSDictionary *)OEMDic;

- (NSString *)textForKey:(NSString *)key;

- (NSString *)objectForKey:(NSString *)key;

- (NSDictionary *)getOEMToFlutterDict;
@end

NS_ASSUME_NONNULL_END
