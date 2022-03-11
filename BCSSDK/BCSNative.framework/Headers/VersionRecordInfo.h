/*
 **
 *****************************************2021-2-3 v3.6.0********************************
 变更记录：
     libmediasdkagent                         11.0.1.210202
         1、声音不再按需生产。发言后直接发送
         1、支持订阅全发言会议音频流，订阅会议音频流默认不混音
         2、去掉会议音频流fec
         3、终端版本号改为：16
         4、发言者音频协议带有音量
         5、修改获取上下行relay地址协议
         6、将接口中使用map的，换成使用数组，解决编译debug版本崩溃的问题
         7、增加文档中窗口模式处理
         1、修改接收端音频去重时间1秒为10秒
             解决两个相同的包相差一秒以上，由接收端收到，无法去重的问题
     libmeetingctrl                           8.1.1.210127
         1.与STP使用全新的私有协议格式。
         2.与STP及各设备客户端应用层，使用新的状态同步机制。
         3.修复对接过程中遇到的问题。
         1.通过修改GMHelper，来规避isSocketValid函数崩溃问题。
         1.修改由于收到多个 8019 导致 摄像头麦克风状态不一致的问题。
         1.修复获取proxy列表的时候可能产生的崩溃问题
     libhostagent                             2.1.10.210201
         1.解决在初始化的时候会导致线程卡住的问题。
         2.修改回调数据错误（多切片只回调最后一片的bug）
             解决：轮询指定600人以上时，指定的人无法全部加入轮询
         1、 修改 clientsession 赋值错误的bug
         2、解决启动时的崩溃问题
         1、增加线程监控
         1.由debug版本编为release版本
         2.修改start的时候，线程未释放可能导致的崩溃问题。
     libMeetingSdk                            5.0.3.210202
         1. 支持订阅音频混音
         2. 打开设备失败后销毁
         3. 支持全发言
     libMediaFramework                        1.1.4.8
     ButelVoiceEngine                         1.0.0.41
         1. 修复崩溃问题。
         2. 版本号增加关键字justmeeting_version。
         1. 优化音视频同步。
         2. neteq计算packet buffer时长时考虑dtx包
         1. 修复语音激励崩溃问题。
         1. 修正语音激励的一些逻辑错误。
         1. 语音激励优化。
         1. 去掉一些调试日志。
         1. 语音激励当前发言者回调中发言者顺序按照网络模块送下来的顺序回调
     libFileUploadClient                      1.5.13.210202
         1.初始化时去掉log::open，以解决第一次运行没有logwriter日志的问题。
         1.修改在IOS设备上发现的内存泄漏问题，具体修改为：常驻工作session创建一次后不进行销毁，以防止定时器随路数据销毁时出现内存泄漏。
             注意：（本版本暂不带阿里云上传通道功能）
         
     版本特性：
         1.兼容性可配置版本
         2.支持stp、Qos多路
         3.支持全发言版本
 ==================================================================
 libmediasdkagent                         11.0.1.210202             钟振磊
 libmeetingqosinforeporttools             2.3.19.200914             张伟
 libmeetingctrl                           8.1.1.210127              程艳芬
 libhostagent                             2.1.10.210201             张寰宇
 libMeetingSdk                            5.0.3.210202              韩雪飞
 libMediaFramework                        1.1.4.8                   李阳
 ButelVoiceEngine                         1.0.0.41                  李阳
 libFileUploadClient                      1.5.9.20200620            张寰宇
 libredcdnbase                            1.0.3.201009              张寰宇
 ButelVideoProcess.framework      1.0.0.2 李阳
 ***************************************************************

 libFileUploadClient.a
 relayagent_11.0.0.210127_ios
 MeetingCtrlAgent_8.1.1.210127_ios
 MeidaFramework    1.1.4.6
 ButelVoiceEngine    1.0.0.39
 ------------------------------------------------
 2020-10-9 v2.5.1***************
 变更记录：
     libmediasdkagent                         10.0.4.200928
         1 通过配置文件配置是否响应接收者期望
         2、终端与relay协议版本号：14：支持按接收端权重计算接收者期望
         3、增加一条资源发布任意条流接口
         4、增加通过接口设置发言者发布规格和接收者消费规格
         5、获取下载服务器改为只使用dp通道，不再通过stpagent和stp获取
         6、下行自适应逻辑转移到relay上，终端只计算CPU自适应和窗口自适应
         7、增加relay代理模块，下行统一使用一个relay代理模块与relay通信，收到数据后再分发给各处理模块
         8、ios上为了减少线程个数，处理线程改为1个
         9. 修复补发无效的问题
         10. 修复进会卡死的问题
         11.修复上行限速关闭流后上升到90p后，无法上升的问题
         12、精简日志
     libmeetingqosinforeporttools             2.3.19.200914
         1、增加线程监控
     libmeetingctrl                           8.0.24.200927
         1.合并dp通道代码。
         2.解决主动下发命令可能会丢失的问题，表现是用户加会可能会出现会议用户数不一致。
         3.之前MPU相关代码未合并到IOS上，合并到IOS，如果没有mpu功能不会走到相关逻辑。
         4.默认使用单协议，重发使用双协议。
         5.修改收到主动下发通知命令时，重复回调上层两次的问题。
     libhostagent                             2.1.9.200929
         1.android 在使用gmudpsocket 的情况下，句柄超过1024，在issocketinvalid函数中使用select会奔溃。
         2.修改回调数据错误（多切片只回调最后一片的bug）
             解决：轮询指定600人以上时，指定的人无法全部加入轮询
         3.由debug版本编为release版本
         4.修改start的时候，线程未释放可能导致的崩溃问题。
     libMeetingSdk                            5.0.1.200917
         1. 支持SVC功能，与相关基础库配合使用
         2. 支持发布3条流
         3. 增加设置内存使用率接口
     libMediaFramework                        1.1.3.1
         1. svc版本正式输出。
     ButelVoiceEngine                         1.0.0.23
         1. 音量计算间隔100ms。
         2. 修复打日志崩溃问题。
     libredcdnbase                            1.0.3.201009
     配置文件更新：
         media_server_agent.xml文件有更新
         
         1.异步模型，网络线程数从1个改成2个
     注意：兼容版本、支持stp多路。
 ===============================================================================================================================================
 libmediasdkagent                         10.0.4.200928             钟振磊
 libmeetingqosinforeporttools             2.3.19.200914             许晓青
 libmeetingctrl                           8.0.24.200927             程艳芬
 libhostagent                             2.1.9.200929              张寰宇
 libMeetingSdk                            5.0.1.200917              韩雪飞
 libMediaFramework                        1.1.3.1                   李阳
 ButelVoiceEngine                         1.0.0.23                  李阳
 libFileUploadClient                      1.5.9.20200620            张寰宇
 libredcdnbase                            1.0.3.201009              张寰宇
 *************************************************************
 
 
 
 *************2020-3-9 v1.1.9************
 变更记录：
     libmediasdkagent      9.2.9.59_svn15544
         1、解决接收资源多线程访问导致崩溃的问题

 ======================================
 libmediasdkagent                         9.2.9.59_svn15544         韩波
 libmeetingqosinforeporttools             2.3.16.27                 许晓青
 libmeetingctrl                           8.0.5.3                   程艳芬
 libhostagent                             1.2.13.23                  韩波
 libMeetingSdk                            2.0.6.14                  韩波
 libMediaFramework                        1.1.2.27                  李阳
 libFileUploadClient                      1.5.8.20                  张寰宇
 ======================================

 ****2020-3-3 v1.1.7**********
 变更记录：
     libmediasdkagent      9.2.9.58
         1、修复Android端未设置窗口模式时，默认收大流的问题

*******************2020-3-1 v1.1.6************************
 变更记录：
     libmediasdkagent      9.2.9.57
         1. 修复码率对应分辨率不对的问题

 ===============================================================================================================================================
 libmediasdkagent                         9.2.9.57          韩波
 libmeetingqosinforeporttools             2.3.16.27                 许晓青
 libmeetingctrl                           8.0.5.3                   程艳芬
 libhostagent                             1.2.13.23                  韩波
 libMeetingSdk                            2.0.6.14                  韩波
 libMediaFramework                        1.1.2.27                  李阳
 libFileUploadClient                      1.5.8.20                  张寰宇


 *********************2020-2-25 v1.1.3********************
 变更记录：
     libmediasdkagent     9.2.8.55_svn_15072
         1. 同步到PC端最新版本
     libmeetingctrl        8.0.5.3
         1.增加如下接口，用以UI从nps拉取ip映射信息后，设置给stpAgent：
             #ifdef __IOS__
             //map方式设置(ip,port)对，map的key/value的字符串格式均为ip：port
             MEETING_CTRL_APIEXPORT_CPP void  UpdateIPPortMap(std::map<std::string,std::string> IPPortmap);
             //json字符串方式设置(ip,port)对
             MEETING_CTRL_APIEXPORT_CPP void  UpdateIPPortMap_Char(char* ipMapChar);
             #endif
         2.配置文件方式支持ip映射，增加StpIPMapConfig.xml，加载路径与Log.xml相同，详见附件。
     libhostagent        2.0.3.31
         1、内外网映射
         2、添加 start接口调用后，注册成功后，回调通知start结果
         3、修改重传超时2000为3000

 */
