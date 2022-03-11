//
//  MediaStreamInfo.h
//  JustMeeting
//
//  Created by dshy1234 on 3/17/16.
//  Copyright © 2016 青牛软件. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Constant.h"
typedef enum {
    StreamStatusUnSubcribi,// 未订阅状态
    StreamStatusPause,  // 暂停状态
    StreamStatusSubcribi     // 订阅状态
}StreamStatus;

@interface MediaStreamInfo : NSObject
/// 数据流类型
@property (assign, nonatomic)SpeakerMediaType mediaType;
//sharetype : 共享类型（1：本地桌面共享  2：远程小工具桌面共享 3：采集卡  5：进程共享  6：白板共享）
@property (assign, nonatomic)int sharetype;
// 同步id
@property (assign, nonatomic)int sysnID;
// 数据流ID
@property (assign, nonatomic)int streamID;
// 白板用的streamid
@property (assign, nonatomic)int whiteBoradStreamid;
//资源ID
@property (assign, nonatomic)int resourceID;
// 分辨率宽
@property (assign,nonatomic) int vdev_w;
// 分辨率高
@property (assign,nonatomic) int vdev_h;
// 拓展信息
@property (nonatomic,strong) NSString * extraInfo ;
// 数据流的状态
@property (assign,nonatomic) StreamStatus status;
///共享标注 1. 支持 ;2. 不支持
@property (nonatomic,assign) BOOL enableDraw;
- (instancetype)initWithDictionaryInfo:(NSDictionary *)dicInfo;
@end
