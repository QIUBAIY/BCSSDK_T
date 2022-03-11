//
//  CNQosInfoModel.h
//  BCSNative
//
//  Created by ButelMac on 2020/12/25.
//  Copyright © 2020 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ConferenceSDK;

typedef enum : NSInteger {
    A_CAM_200 = 0,
    V_CAM_100 = 1, //大流
    V_CAM_101 = 2, //小流
    V_CAM_102 = 3, //占位流
    V_CAM_1   = 4, //关闭
    V_DOC_300 = 5,
    unknown = -1,
} QosInfoType;

typedef enum : NSInteger {
    Level_0 = 0,
    Level_1 = -1,
    Level_2 = -2,
    Level_3 = -3,
    Level_4 = -4,
    Level_5 = -5,
    Level_unknown = -100,
} QosInfoLevel;//档位

@interface CNQosInfoModel : NSObject
@property (nonatomic,copy) NSString *userID;
@property (nonatomic,copy) NSString *qosKey;
@property (nonatomic,copy) NSString *qosTitle;
@property (nonatomic,copy) NSString *qosValue;

- (NSString *)conversionWithTitle:(NSString *)title ;
- (NSString *)getSessionTitle:(NSString *)key;
+ (NSArray *)ConversionDataWithTitle:(NSString *)title dataInfo:(NSArray *)dataArr;

+ (NSMutableAttributedString *)qosInfoFormatWithDataArr:(NSArray *)dataArr
                                               eventSDK:(ConferenceSDK *)eventSDK
                                        attributedWidth:(CGFloat)attributedWidth
                                             indexPatch:(NSIndexPath *)indexPatch
                                         calculateBlock:(void(^)(CGFloat height, NSIndexPath *indexPatch))calculateBlock;
+ (QosInfoType)qosInfoType:(NSArray *)arr;
+ (NSString *)qosStatus:(NSArray *)streamQosInfo;
+ (NSString *)qosInfoTypeStr:(NSArray *)streamQosInfo;
+ (QosInfoLevel)getQosLevel;
/////QOS信息 key
///// baseInfo title
///// 音频缓冲区
//@property (nonatomic,copy)NSString *title_AudioStrategy;
///// CPU|内存
//@property (nonatomic,copy)NSString *title_CPU_MEM;
///// 下行探测带宽
//@property (nonatomic,copy)NSString *title_DownBW;
///// 下行码率
//@property (nonatomic,copy)NSString *title_DownSpeed;
///// 下行码率峰值
//@property (nonatomic,copy)NSString *title_DownSpeedPeak;
//@property (nonatomic,copy)NSString *title_UBWResI;
///// 上行带宽
//@property (nonatomic,copy)NSString *title_UpBW;
///// 上行探测带宽
//@property (nonatomic,copy)NSString *title_UpBWnew;
///// 上行码率
//@property (nonatomic,copy)NSString *title_UpSpeed;
///// 上行码率峰值
//@property (nonatomic,copy)NSString *title_UpSpeedPeak;
///// 自适应模式
//@property (nonatomic,copy)NSString *title_adptionMode;
///// 流量峰值
//@property (nonatomic,copy)NSString *title_cfnDetectMaxBW;
///// 网络类型
//@property (nonatomic,copy)NSString *title_signal;
/////  value  streamInfo title
///// key当前带宽
//@property (nonatomic,copy)NSString *title_V_CAM_100_CurUseBW;
///// key视频编码
//@property (nonatomic,copy)NSString *title_V_CAM_100_codec;
///// key数据补发次数
//@property (nonatomic,copy)NSString *title_V_CAM_100_dataResendCount;
///// key数据|校验包补发份数
//@property (nonatomic,copy)NSString *title_V_CAM_100_d_c_RetransSend;
///// key数据|校验包发送份数
//@property (nonatomic,copy)NSString *title_V_CAM_100_d_c_SendCount;
///// key视频FEC比例
//@property (nonatomic,copy)NSString *title_V_CAM_100_fecRatio;
///// key视频历史丢包率
//@property (nonatomic,copy)NSString *title_V_CAM_100_hisLossInfo;
///// key档位|码率|帧数
//@property (nonatomic,copy)NSString *title_V_CAM_100_level;
///// key视频码率
//@property (nonatomic,copy)NSString *title_V_CAM_100_zbiteRate;
///// key视频帧率
//@property (nonatomic,copy)NSString *title_V_CAM_100_zframRate;
///// key丢包信息
//@property (nonatomic,copy)NSString *title_V_CAM_100_zlossInfo;
///// key视频分辨率
//@property (nonatomic,copy)NSString *title_V_CAM_100_zpicFormat;
//@property (nonatomic,copy)NSString *title_V_CAM_100_TLossInfo;
///// key视频接收流类型
//@property (nonatomic,copy)NSString *title_V_CAM_100_subResID;
///// key视频时延（ms）
//@property (nonatomic,copy)NSString *title_V_CAM_100_waitTime;
///// key当前带宽
//@property (nonatomic,copy)NSString *title_V_CAM_101_CurUseBW;
///// key视频编码
//@property (nonatomic,copy)NSString *title_V_CAM_101_codec;
///// key数据补发次数
//@property (nonatomic,copy)NSString *title_V_CAM_101_dataResendCount;
///// key数据|校验包补发份数
//@property (nonatomic,copy)NSString *title_V_CAM_101_d_c_RetransSend;
///// key数据|校验包发送份数
//@property (nonatomic,copy)NSString *title_V_CAM_101_d_c_SendCount;
///// key视频FEC比例
//@property (nonatomic,copy)NSString *title_V_CAM_101_fecRatio;
///// key视频历史丢包率
//@property (nonatomic,copy)NSString *title_V_CAM_101_hisLossInfo;
///// key档位|码率|帧数
//@property (nonatomic,copy)NSString *title_V_CAM_101_level;
///// key视频码率
//@property (nonatomic,copy)NSString *title_V_CAM_101_zbiteRate;
///// key视频帧率
//@property (nonatomic,copy)NSString *title_V_CAM_101_zframRate;
///// key丢包信息
//@property (nonatomic,copy)NSString *title_V_CAM_101_zlossInfo;
///// key视频分辨率
//@property (nonatomic,copy)NSString *title_V_CAM_101_zpicFormat;
//
/////  value  当前带宽
//@property (nonatomic,copy)NSString *title_A_CAM_200_CurUseBW;
/////  value  音频码率
//@property (nonatomic,copy)NSString *title_A_CAM_200_biteRate;
/////  value  音频编码
//@property (nonatomic,copy)NSString *title_A_CAM_200_codec;
/////  value  音频补发请求次数
//@property (nonatomic,copy)NSString *title_A_CAM_200_dataResendCount;
/////  value  数据|校验包补发份数
//@property (nonatomic,copy)NSString *title_A_CAM_200_d_c_RetransSend;
/////  value  数据|校验包发送份数
//@property (nonatomic,copy)NSString *title_A_CAM_200_d_c_SendCount;
/////
//@property (nonatomic,copy)NSString *title_A_CAM_200_emptyPacketRate;
/////  value  音频FEC比例
//@property (nonatomic,copy)NSString *title_A_CAM_200_fecRatio;
/////  value  连续4个空音包个数
//@property (nonatomic,copy)NSString *title_A_CAM_200_fourToTenPackets;
/////  value  音频历史丢包率
//@property (nonatomic,copy)NSString *title_A_CAM_200_hisLossInfo;
/////  value  档位|码率|帧数
//@property (nonatomic,copy)NSString *title_A_CAM_200_level;
/////  value  连续超过10个空音包个数
//@property (nonatomic,copy)NSString *title_A_CAM_200_moreThanTenPackets;
/////  value  连续1个空音包个数
//@property (nonatomic,copy)NSString *title_A_CAM_200_onePacket;
/////  value  连续3个空音包个数
//@property (nonatomic,copy)NSString *title_A_CAM_200_threePackets;
/////  value  连续2个空音包个数
//@property (nonatomic,copy)NSString *title_A_CAM_200_twoPackets;
/////  value  音频整体丢包率
//@property (nonatomic,copy)NSString *title_A_CAM_200_totalLossInfo;
/////  value  音频时延（ms）
//@property (nonatomic,copy)NSString *title_A_CAM_200_waitTime;
/////  value  丢包信息
//@property (nonatomic,copy)NSString *title_A_CAM_200_zlossInfo;
//
/////  value  流量
//@property (nonatomic,copy)NSString *title_bwReserveInfo;
/////  value  探测带宽
//@property (nonatomic,copy)NSString *title_bwRet;
/////  value  当前历史延时
//@property (nonatomic,copy)NSString *title_curHisDelay;
/////  value  下行时延
//@property (nonatomic,copy)NSString *title_downDelay;
/////  value  下行实时数据
//@property (nonatomic,copy)NSString *title_downNetSpeed;
///// 上行时延
//@property (nonatomic,copy)NSString *title_upDelay;
///// 上行流量
//@property (nonatomic,copy)NSString *title_upNetSpeed;
/////  value  服务器
//@property (nonatomic,copy)NSString *title_server;
//@property (nonatomic,copy)NSString *title_server_first;
//@property (nonatomic,copy)NSString *title_speaker_parent_child0;
//@property (nonatomic,copy)NSString *title_speaker_parent_child1;
//@property (nonatomic,copy)NSString *title_speaker_parent_child2;
//@property (nonatomic,copy)NSString *title_speaker_resid_100;
//@property (nonatomic,copy)NSString *title_speaker_resid_101;
//@property (nonatomic,copy)NSString *title_speaker_resid_102;
//@property (nonatomic,copy)NSString *title_status;
//@property (nonatomic,copy)NSString *title_userid;



/////QOS信息 key
/////  baseInfo title
/////  value  音频缓冲区
//@property (nonatomic,copy)NSString *AudioStrategy;
/////  value  CPU|内存
//@property (nonatomic,copy)NSString *CPU_MEM;
/////  value  下行探测带宽
//@property (nonatomic,copy)NSString *DownBW;
/////  value  下行码率
//@property (nonatomic,copy)NSString *DownSpeed;
/////  value  下行码率峰值
//@property (nonatomic,copy)NSString *DownSpeedPeak;
//@property (nonatomic,copy)NSString *UBWResI;
/////  value  上行带宽
//@property (nonatomic,copy)NSString *UpBW;
/////  value  上行探测带宽
//@property (nonatomic,copy)NSString *UpBWnew;
/////  value  上行码率
//@property (nonatomic,copy)NSString *UpSpeed;
/////  value  上行码率峰值
//@property (nonatomic,copy)NSString *UpSpeedPeak;
/////  value  自适应模式
//@property (nonatomic,copy)NSString *adptionMode;
/////  value  流量峰值
//@property (nonatomic,copy)NSString *cfnDetectMaxBW;
/////  value  网络类型
//@property (nonatomic,copy)NSString *signal;
//
//
/////  value  streamInfo title
///// value  当前带宽
//@property (nonatomic,copy)NSString *V_CAM_100_CurUseBW;
///// value  视频编码
//@property (nonatomic,copy)NSString *V_CAM_100_codec;
///// value  数据补发次数
//@property (nonatomic,copy)NSString *V_CAM_100_dataResendCount;
///// value  数据|校验包补发份数
//@property (nonatomic,copy)NSString *V_CAM_100_d_c_RetransSend;
///// value  数据|校验包发送份数
//@property (nonatomic,copy)NSString *V_CAM_100_d_c_SendCount;
///// value  视频FEC比例
//@property (nonatomic,copy)NSString *V_CAM_100_fecRatio;
///// value  视频历史丢包率
//@property (nonatomic,copy)NSString *V_CAM_100_hisLossInfo;
///// value  档位|码率|帧数
//@property (nonatomic,copy)NSString *V_CAM_100_level;
///// value  视频码率
//@property (nonatomic,copy)NSString *V_CAM_100_zbiteRate;
///// value  视频帧率
//@property (nonatomic,copy)NSString *V_CAM_100_zframRate;
///// value  丢包信息
//@property (nonatomic,copy)NSString *V_CAM_100_zlossInfo;
///// value  视频分辨率
//@property (nonatomic,copy)NSString *V_CAM_100_zpicFormat;
//@property (nonatomic,copy)NSString *V_CAM_100_TLossInfo;
///// value  视频接收流类型
//@property (nonatomic,copy)NSString *V_CAM_100_subResID;
///// value  视频时延（ms）
//@property (nonatomic,copy)NSString *V_CAM_100_waitTime;
///// value  当前带宽
//@property (nonatomic,copy)NSString *V_CAM_101_CurUseBW;
///// value  视频编码
//@property (nonatomic,copy)NSString *V_CAM_101_codec;
///// value  数据补发次数
//@property (nonatomic,copy)NSString *V_CAM_101_dataResendCount;
///// value  数据|校验包补发份数
//@property (nonatomic,copy)NSString *V_CAM_101_d_c_RetransSend;
///// value  数据|校验包发送份数
//@property (nonatomic,copy)NSString *V_CAM_101_d_c_SendCount;
///// value  视频FEC比例
//@property (nonatomic,copy)NSString *V_CAM_101_fecRatio;
///// value  视频历史丢包率
//@property (nonatomic,copy)NSString *V_CAM_101_hisLossInfo;
///// value  档位|码率|帧数
//@property (nonatomic,copy)NSString *V_CAM_101_level;
///// value  视频码率
//@property (nonatomic,copy)NSString *V_CAM_101_zbiteRate;
///// value  视频帧率
//@property (nonatomic,copy)NSString *V_CAM_101_zframRate;
///// value  丢包信息
//@property (nonatomic,copy)NSString *V_CAM_101_zlossInfo;
///// value  视频分辨率
//@property (nonatomic,copy)NSString *V_CAM_101_zpicFormat;
//
/////  value  当前带宽
//@property (nonatomic,copy)NSString *A_CAM_200_CurUseBW;
/////  value  音频码率
//@property (nonatomic,copy)NSString *A_CAM_200_biteRate;
/////  value  音频编码
//@property (nonatomic,copy)NSString *A_CAM_200_codec;
/////  value  音频补发请求次数
//@property (nonatomic,copy)NSString *A_CAM_200_dataResendCount;
/////  value  数据|校验包补发份数
//@property (nonatomic,copy)NSString *A_CAM_200_d_c_RetransSend;
/////  value  数据|校验包发送份数
//@property (nonatomic,copy)NSString *A_CAM_200_d_c_SendCount;
/////
//@property (nonatomic,copy)NSString *A_CAM_200_emptyPacketRate;
/////  value  音频FEC比例
//@property (nonatomic,copy)NSString *A_CAM_200_fecRatio;
/////  value  连续4个空音包个数
//@property (nonatomic,copy)NSString *A_CAM_200_fourToTenPackets;
/////  value  音频历史丢包率
//@property (nonatomic,copy)NSString *A_CAM_200_hisLossInfo;
/////  value  档位|码率|帧数
//@property (nonatomic,copy)NSString *A_CAM_200_level;
/////  value  连续超过10个空音包个数
//@property (nonatomic,copy)NSString *A_CAM_200_moreThanTenPackets;
/////  value  连续1个空音包个数
//@property (nonatomic,copy)NSString *A_CAM_200_onePacket;
/////  value  连续3个空音包个数
//@property (nonatomic,copy)NSString *A_CAM_200_threePackets;
/////  value  连续2个空音包个数
//@property (nonatomic,copy)NSString *A_CAM_200_twoPackets;
/////  value  音频整体丢包率
//@property (nonatomic,copy)NSString *A_CAM_200_totalLossInfo;
/////  value  音频时延（ms）
//@property (nonatomic,copy)NSString *A_CAM_200_waitTime;
/////  value  丢包信息
//@property (nonatomic,copy)NSString *A_CAM_200_zlossInfo;
//
/////  value  流量
//@property (nonatomic,copy)NSString *bwReserveInfo;
/////  value  探测带宽
//@property (nonatomic,copy)NSString *bwRet;
/////  value  当前历史延时
//@property (nonatomic,copy)NSString *curHisDelay;
/////  value  下行时延
//@property (nonatomic,copy)NSString *downDelay;
/////  value  下行实时数据
//@property (nonatomic,copy)NSString *downNetSpeed;
///// 上行时延
//@property (nonatomic,copy)NSString *upDelay;
///// 上行流量
//@property (nonatomic,copy)NSString *upNetSpeed;
/////  value  服务器
//@property (nonatomic,copy)NSString *server;
//@property (nonatomic,copy)NSString *server_first;
//@property (nonatomic,copy)NSString *speaker_parent_child0;
//@property (nonatomic,copy)NSString *speaker_parent_child1;
//@property (nonatomic,copy)NSString *speaker_parent_child2;
//@property (nonatomic,copy)NSString *speaker_resid_100;
//@property (nonatomic,copy)NSString *speaker_resid_101;
//@property (nonatomic,copy)NSString *speaker_resid_102;
//@property (nonatomic,copy)NSString *status;
//@property (nonatomic,copy)NSString *userid;

@end

NS_ASSUME_NONNULL_END
