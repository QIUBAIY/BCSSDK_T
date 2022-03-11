//
//  ConstConfig.h
//
//  Created by dutingfu on 2017/2/21.
//  Copyright © 2017年 dutingfu. All rights reserved.
//

#import <Foundation/Foundation.h>
//如下静态变量必须通过nps获取参数并初始化
static NSString *npsWebDomain = @"https://c.cicdi.com/cme/nps_x2/";
static NSString *npsSlaveWebDomain = @"https://c.cicdi.com/cme/nps_x2/";

// meeting manage server address
static NSString *UPLOAD_IMAGE_URL_SUFFIX = @"/dfs_upload/NubePhotoUpload"; // 头像上传后缀

static NSString *HTTP_S = @"http";
static NSString *HTTP_SCHEMA = @"http://";
/// 请求参数
static NSString *PARAM_TOKEN = @"token";
static NSString *PARAM_INVOTEDUSERS = @"invotedUsers";
static NSString *PARAM_EFFECTIVEHOUR= @"effectiveHour";
static NSString *PARAM_INVOTEDPHONES = @"invotedPhones";

static NSString *PARAM_MEETINGTYPE = @"meetingType";
static NSString *PARAM_MEETINGBEGINTIME = @"beginDateTime";
static NSString *PARAM_MEETINGENDTIME = @"endDateTime";

static NSString *PARAM_TOPIC= @"topic";
static NSString *PARAM_APP= @"app";
static NSString *PARAM_SMS_TYPE = @"smsType";
static NSString *PARAM_FILEDATA = @"fileData";
static NSString *PARAM_INVITERPHONEID = @"inviterPhoneId";
static NSString *PARAM_INVITERNAME = @"inviterName";
//static NSString *PARAM_DATA = @"data";
static NSString *PARAM_COUNT = @"count";
static NSString *PARAM_CREATORNAME = @"creatorName";
static NSString *PARAM_CREATETIME = @"createTime";
static NSString *PARAM_DATETIME = @"datetime";
static NSString *PARAM_CONTACTINFO = @"contactInfo";
static NSString *PARAM_EXPECTSTARTTIME = @"expectStarttime";
static NSString *PARAM_DEVMODEL = @"devModel";
static NSString *PARAM_REQUESTPARAM = @"requestParam";
static NSString *PARAM_SERIALNUMBER = @"serialNumber";
static NSString *PARAM_PRODUCT = @"product";
static NSString *PARAM_VERSION = @"version";
static NSString *PARAM_TERMINAL = @"terminal";
static NSString *PARAM_PROJECT = @"project";
static NSString *PARAM_UTCTIME = @"utctime";
static NSString *PARAM_ADMINPHONEID = @"adminPhoneId";
static NSString *PARAM_LOGIN = @"Login";
static NSString *PARAM_BINDONACCOUNT = @"BindOnAccount";
static NSString *PARAM_CLIENTREPORT = @"ClientReportInfo";
static NSString *PARAM_GETACCOUNTINFO = @"GetAccountInfo";
static NSString *PARAM_MODIFYACCOUNTINFO = @"ModifyAccountInfo";
static NSString *PARAM_CREATEMEETING = @"CreateMeeting";
static NSString *PARAM_EXTENDTOKEN = @"ExtendToken";
static NSString *PARAM_GETNOWMEETINGS = @"GetNowMeetings";
static NSString *PARAM_MODIFYMEETINGINVITERS = @"ModifyMeetingInviters";
static NSString *PARAM_BINDTOKEN = @"BindToken";
static NSString *PARAM_GETMEETINGINVITATIONSMS = @"GetInvitationSMS";//@"GetMeetingInvitationSMS"
static NSString *PARAM_GETMEETINGZBINVITATIONSMS = @"GetMeetingZBInvitationSMS";

static NSString *PARAM_GETTIMENOW = @"GetTimeNow";
static NSString *PARAM_SUGGESTION = @"Suggestion";
static NSString *PARAM_VERFYMEETINGNO = @"VerifyMeetingNo";
static NSString *PARAM_GETMEETINGSPWD = @"GetMeetingPwd";
static NSString *PARAM_RETSETMEETINGPWD= @"ResetMeetingPwd";
static NSString *PARAM_EDITMEETING = @"EditMeeting";
static NSString *PARAM_GETMEETINGS = @"GetMeetings";
static NSString *PARAM_MODIFYATTENDMEETINGNAME = @"setAccountAttr";
static NSString *PARAM_ENTMEMBERLOGIN = @"entMemberLogin";
static NSString *PARAM_LOGIN4MOBILE = @"Login4Mobile";
static NSString *PARAM_CHECK_APP_VERSION = @"CheckVersion";
static NSString *PARAM_USERCNTER_GETNUBENUMBERLIST = @"getNubeNumberList";
static NSString *PARAM_USERCNTER_REGISTERACCOUNT = @"registerAccount";
static NSString *PARAM_USERCNTER_ACTIVATEACCOUNT = @"activateAccount";

static NSString *PARAM_SEARCHACCOUNT = @"searchAccount";
static NSString *PARAM_SEARCHACCOUNTBYMOBILE = @"searchAccountByMobile";
static NSString *PARAM_USERCNTER_RESENDACTVIATECODE = @"reSendActivateCode";
static NSString *PARAM_USERCNTER_CHANGEPASSWORD = @"changePassword";
static NSString *PARAM_USERCNTER_SENDCODEFORRESETPWD = @"sendCodeForResetPwd";
static NSString *PARAM_USERCNTER_RESETPASSWORD = @"resetPassword";
static NSString *PARAM_USERCNTER_DOWNLOADCONTACTDATA = @"downloadContactsData";
static NSString *PARAM_USERCNTER_UPLOADCONTACTDATA = @"uploadContactsData";
static NSString *PARAM_MEETINGMANAGE_STOREFEEDBACKTEXT = @"StoreFeedbackText";


static NSString *TOKEN = @"token";
static NSString *EFFECTIVE_TIME = @"effectiveTime";
static NSString *NAME = @"name";
static NSString *PHONE_ID = @"phoneId";
static NSString *USER_INFO = @"userInfo";
static NSString *NICK_NAME = @"nickname";
static NSString *USE_ENDTIME = @"useEndTime";
static NSString *NUBENUMBER = @"nubeNumber";
static NSString *UID = @"uids";
static NSString *NEWPASSWORD = @"newPassword";
static NSString *VERIFICATIONCODE = @"verificationCode";
static NSString *PARAM_SERVICE = @"service";
static NSString *PARAM_PARAMS = @"params";
static NSString *SERVICETYPE = @"serviceType";
static NSString *USESTARTTIME = @"useStartTime";
static NSString *HEADURL = @"headUrl";
static NSString *MOBILE = @"mobile";

static NSString *ACCESS_TOKEN = @"accessToken";
static NSString *RESULT = @"result";
static NSString *RESPONSE = @"response";
static NSString *RC = @"rc";
static NSString *RD = @"rd";
static NSString *MEETING_ID = @"meetingId";
static NSString *PARAM_USERCONTACT = @"userContact";
static NSString *ADMIN_PHONE_ID = @"adminPhoneId";
static NSString *STATUS = @"status";
static NSString *MESSAGE = @"message";
static NSString *NEWCODE = @"code";
static NSString *NEWMESSAGE = @"msg";

static NSString *STARTLINENO = @"startLineNo";
static NSString *MAXNUM = @"maxNum";
static NSString *TIMESTAMP = @"timestamp";
static NSString *HASDELETE = @"hasDelete";
static NSString *CONTACTS = @"contacts";

static NSString *ACCOUNT = @"account";
static NSString *PASSWORD = @"password";
static NSString *ACTIVATECODE = @"activateCode";
static NSString *APPTYPEConst = @"appType";
static NSString *PRODUCTIDConst = @"productId";
static NSString * PRODUCTTYPE = @"productType";
static  int ERROR_CODE_INVALIDATE_PARAM = -1;
static NSString *USERTYPE = @"userType";
static NSString *INVITERPHONEID = @"inviterPhoneId";
static NSString *INVITERNAME = @"inviterName";
#define PROD_ID                     @"prod002"
#define DEVICE_TYPE                 @"IOS_JIHY"

//DataErrorCode
static int DATA_INVALIDATE_PARSER = -0x20001;
static int DATA_INVALIDATE_RESPONSE_FORMAT = -0x20002;
static int CLASS_CAST_EXCEPTION = -0x20003;
static int NUMBER_FORMAT_EXCEPTION = -0x20004;


static int HTTP_OK = 0;               //成功
static int HTTP_PARAMS_ERROR = -1;    //序列化参数出错
static int HTTP_IS_WORKING = -2;      //正在工作
static int HTTP_CREAT_ERROR = -3;     //创建HTTP出错
static int HTTP_RESULT_ERROR = -4;     //返回结果错误



@interface ConstConfig : NSObject

+ (NSString *) getMobileHelpDomain;
+ (void) setMobileHelpDomain:(NSString *)url;
//设置会议SDK中的主NPS地址
+ (NSString *) getBmsWebDomain;
+ (void) setBmsWebDomain:(NSString *)url;
//设置会议SDK中的副NPS地址
+ (NSString *) getSlaveBmsWebDomain;
+ (void) setSlaveBmsWebDomain:(NSString *)url;

//设置会议上传地址
+ (NSString *) LogUpload_serverIp;
+ (void) setLogUpload_serverIp:(NSString *)url;
//设置会议SDK中的PASS地址
+ (NSString *) getPassDomain;
+ (void) setPassDomain:(NSString *)url;

+ (NSString *) getPassUserAuthUrl;
+ (NSString *) getPassCheckMeetingIdAndMseetingPwdUrl;
//服务器参数
+ (void)setServiceArr:(NSArray *)serviceA ;
+ (NSArray *)getServiceArr;

//获取最大参会方人数
+ (NSString *) getMaxSpeakerNum;
+ (void) setMaxSpeakerNum:(NSString *)num;
//3.1需求
+ (NSString *) getMobileUrl;
+ (void) setMobileUrl:(NSString *)url;

+ (NSString *) getSlave_MobileUrl;
+ (void) setSlave_MobileUrl:(NSString *)url;

+ (NSString *) getAppLogPath;
+ (void) setAppLogPath:(NSString *)path;

+ (NSString *) getLogRecvServerUrlData;
+ (void) setLogRecvServerUrlData:(NSString *)url;

+ (void) setEnterPriseUserCenterWebDomain:(NSString *)url;
+ (void) setPersonalUserCenterWebDomain:(NSString *)url;
+ (void) setImgUpdateServerWebDomain:(NSString *)url;
+ (NSString *)getImgUpdateServerWebDomain;

+ (void) setPersonalContactWebDomain:(NSString *)url;
+ (void)setReportServeURLServerWebDomain:(NSString *)url;
+ (NSString *)getReportServeURLServerWebDomain;
+ (NSString *) getSearchAccount;
+ (NSString *) getUploadContactsData;
+ (NSString *) getDownloadContactsData;
+ (NSString *) getResetPassword;
+ (NSString *) getSendCodeForResetPwd;
+ (NSString *) getChangePassword;
+ (NSString *) getSearchAccountByMobile;
+ (NSString *) getSetAccountAttr;
+ (NSString *) getReSendActivateCode;
+ (NSString *) getAcquireAccountInfo;
+ (NSString *) getLogin4Mobile;
+ (NSString *) getActivateAccount;
+ (NSString *) getRegisterAccount;
+ (NSString *) getGetNubeNumberList;
+ (NSString *) getVerifyMeetingNoUrl;
+ (NSString *) getAttendMeetingName;
+ (NSString *) getAuthUrl;
+ (NSString *) getBindTokenUrl;
+ (NSString *) getForwardURL;
+ (NSString *) getGetMeetingInvitationSMSUrl;
+ (NSString *) getmodifyAccountInfoUrl;
+ (NSString *) getmodifyMeetingInvitersUrl;
+ (NSString *) getQueryMeetingListNowUrl;
+ (NSString *) getRefillTokenUrl;
+ (NSString *) getBindOnAccountUrl;
+ (NSString *) getGetAccountInfoUrl;
+ (NSString *) getCreateMeetingUrl;
+ (NSString *) getEditMeetingUrl;
+ (NSString *) getGetMeetingsUrl;
+ (NSString *) getGetTimeNowUrl;
+ (NSString *) getSuggestionUrl;
+ (NSString *) getClientReportInfo;
+ (NSString *) getNpsUrl;
+ (NSString *) getSMSUrl;
+ (NSString *) getMeetingInfoUrl;
+ (NSString *) getMeetingManageUrl ;
+ (NSString *) getSlaveNpsUrl;
+ (NSString*) getPersonerAuthUrl;
+ (NSString *) getGetSlaveMeetingUrl;
+ (NSString *) getMeetingManagementHttpUrlPrefix;
+ (NSString *) getSlaveMeetingManagermentHttpUrlPrefix;
+ (void)setNps:(NSString *)nps;
+ (void)setSlaveNps:(NSString *)slavenps;
+ (void)setWhiteListString:(NSString *)WhiteList;
+ (NSString *)getWhiteListString;

/** 支持代理服务器  HttpIpMap   RecverIPMap HostIpMap RelayUrlMap StpUrlMap*/
/// 是否支持代理服务器
+ (void)setSupportProxyServer:(BOOL)ProxyServer;
//StpUrlMap
+ (void)setHttpIpMap:(NSString*)httpIpMap;
//RecverIPMap
+ (void)setRecverIPMap:(NSString*)recverIPMap;
//HostIpMap
+ (void)setHostIpMap:(NSString*)hostIpMap;
//RecverIPMap
+ (void)setRelayUrlMap:(NSString*)relayUrlMap;
//StpUrlMap
+ (void)setStpUrlMap:(NSString*)stpUrlMap;
//DomainMapping
+ (void)setDomainMapping:(NSString*)domainMapping;
/// 获取是否支持代理服务器
+ (BOOL)getSupportProxyServer;
+ (NSString *) getHttpIpMap;
+ (NSString *) getRecverIPMap;
+ (NSString *) getHostIpMap;
+ (NSString *) getRelayUrlMap;
+ (NSString *) getStpUrlMap;
+ (NSString *) getCNDomainMapping;
/** 支持统一路由 unifiedRC*/
+ (void)setNetID:(NSString *)defaultNetID;
+ (NSString *)getNetID;
+ (void)setSupportUnifiedRC:(BOOL)enable;
+ (BOOL)getSupportUnifiedRC;
+ (void)setUnifiedRCUrlsString:(NSString *)UnifiedRCUrlsString;
+ (NSString *)UnifiedRCUrlsString;
+ (void)setUnifiedRCUrls:(NSArray<NSString *>*)UnifiedRCUrls;
+ (NSArray<NSString *>*)getUnifiedRCUrls;

+ (void)setNetagent_IP:(NSString *)Netagent_IP;
+ (NSString *)getNetagent_IP;
+ (void)setNetagent_PROT:(NSString *)Netagent_PROT;
+ (NSString *)getNetagent_PROT;
+ (void)setNetagent_Agreement:(BOOL)Netagent_Agreement;
+ (BOOL )getNetagent_Agreement;


@end
