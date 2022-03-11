//
//  LogFileUpLoad.h
//  JMeetingFramework
//
//  Created by dutingfu on 2017/3/24.
//  Copyright © 2017年 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LogFileUpLoadManager : NSObject
/*
 开始日志上传
 userID 用户id
 logSerurl  服务器url
 logpath 本地日志文件路径
 */
+ (int)startUploadLog:(NSString *)userID
            logSerurl:(NSString *)url
          projectName:(NSString *)projectName
              logPath:(NSString *)logpath
;

/*
 停止日志上传
 */
+ (void)stopUploadLog;


/**
 *  设置视讯号
 * @param userId  设备视讯号
 * @return
 */

+ (int)SetUserID:(NSString *)userID;
/**
 *  设置 http 上传最大速度
 * @param speed   单位：KB/s, 设置为 0 时不限速
 * @return
 */

+ (int)SetHttpUploadSpeedMax:(long )speed;
/**
 *  通知强制上传日志文件
 * @param force   true：强制，false：非强制
 * @return
 */

+ (int)NoticeMandatoryUploadLog:(BOOL )force;

+(NSString *)getLogUserID;
+(NSString *)getLogSerIp;
+(NSInteger )getLogSerPort;
+(NSString *)getLogProjectName;



@end
