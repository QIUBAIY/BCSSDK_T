//
//  MeetingSpeakerInfo.h
//  JustMeeting
//
//  Created by dshy1234 on 3/16/16.
//  Copyright © 2016 青牛软件. All rights reserved.
//



#import <Foundation/Foundation.h>
#import "MediaStreamInfo.h"

@interface MeetingSpeakerInfo : NSObject
//发言者摄像头开关的状态，类型int,1为打开摄像头；2为关闭摄像头
//@property (assign,nonatomic)int camStaus;
// 标记mic 的关闭打开状态 YES 打开 NO 关闭，
@property (assign,nonatomic) BOOL micStatus;
// 标记 camera的状态 YES 打开 NO 关闭，
@property (assign,nonatomic) BOOL cameraStatus;
//发言者类型，1为主讲人，2为普通发言者。
@property (assign,nonatomic)int speakerType;
 //屏幕分享状态，1屏幕分享者，2普通发言者
@property (assign,nonatomic)int screenShareInfo;

// 标记视频是否被其他人关闭
@property (assign,nonatomic) BOOL videoisClosed;

// 扬声器是否关闭 YES 关闭 ；NO打开
@property (assign,nonatomic) BOOL isCloseSpeaker;
@property (strong,nonatomic)NSString *accountID;// 参会方视讯号
@property (strong,nonatomic)NSString *accountName;// 参会方昵称
@property (strong,nonatomic)NSMutableDictionary *streams;// 参会方数据流信息

@property (strong,nonatomic) MediaStreamInfo * lastTimeStreamInfo;/// 参会方最后一次的流信息
/// 根据资源id获取数据流信息
- (MediaStreamInfo *)getMediaStreamInfoWith:(int)resourceid;
@property (nonatomic,assign) int voiceStreamID;

@property (nonatomic,assign) BOOL vocieSub;// 是否订阅音频:YES 订阅；NO不订阅
@property (nonatomic,assign) BOOL videoSub;// 是否订阅视频:YES 订阅；NO不订阅
@end
