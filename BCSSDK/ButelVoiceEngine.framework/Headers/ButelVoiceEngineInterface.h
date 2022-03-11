#ifndef BUTEL_VOICE_ENGINE_INTERFACE_H
#define BUTEL_VOICE_ENGINE_INTERFACE_H

#include <stdint.h>
#include <stddef.h>

#if defined(ANDROID) || defined(__ANDROID__)
#include <jni.h>
#endif

typedef void(*LogFun)(const char *fmt, ...);

class ButelMediaCallbackInterface
{
public:
	virtual ~ButelMediaCallbackInterface() {}
	virtual void OnAudioFrame(const char *data, int datalen, float volume) = 0;
};

class ButelAudioDBCallbackInterface
{
public:
	virtual ~ButelAudioDBCallbackInterface(){}
	virtual void OnAudioDB(uint32_t ssrc, float db) = 0;
};


class ButelRawAudioSinkInterface {
public:
	virtual ~ButelRawAudioSinkInterface() {}
	virtual void OnRawAudio(const int16_t* data, size_t samples_per_channel,
		int sample_rate, size_t channels, int64_t timestamp) = 0;
};

class ButelMixRawAudioSinkInterface {
public:
	virtual ~ButelMixRawAudioSinkInterface(){}
	virtual void OnMixRawAudio(const int16_t* data, size_t samples_per_channel,
		int sample_rate, size_t channels, int64_t timestamp) = 0;
};

class ButelVoiceEngineInterface
{
public:
	~ButelVoiceEngineInterface() {}
	virtual bool Init() = 0;
	virtual bool UnInit() = 0;
	virtual bool AddSendStream(uint32_t ssrc, const char *device = NULL) = 0;
	virtual bool RemoveSendStream(uint32_t ssrc) = 0;
	virtual bool AddRecvStream(uint32_t ssrc, const char *device = NULL) = 0;
	virtual bool RemoveRecvStream(uint32_t ssrc) = 0;
	virtual bool SetSend(bool send) = 0;
	virtual bool SetPlayout(bool playout) = 0;
	virtual bool RegisterMediaCallback(uint32_t ssrc, ButelMediaCallbackInterface *callback) = 0;
	virtual bool OnPacketReceived(const char *data, int datalen) = 0;
	virtual uint32_t GetPlayoutTimeStamp(uint32_t ssrc) = 0;
	virtual bool RegisterAudioDBCallback(uint32_t ssrc, ButelAudioDBCallbackInterface *callback) = 0;
	virtual void SetMinimumPlayoutDelay(uint32_t ssrc, int delay_ms) = 0;
	virtual bool StartShareAudio(const char *device) = 0;
	virtual bool StopShareAudio() = 0;
	virtual bool SetRawAudioSink(uint32_t ssrc, ButelRawAudioSinkInterface* sink) = 0;
	virtual bool SetMixRawAudioSink(ButelMixRawAudioSinkInterface* sink) = 0;
	virtual void EnableDTX(bool enable_dtx) = 0;
	virtual bool GetDelay(uint32_t ssrc, int& delay) = 0;
	virtual void FlushBuffers(uint32_t ssrc) = 0;

    /**
     * 选择回声消除模式，支持动态修改，建议初始化引擎前配置。默认使能 AEC
     * @param isEnableAEC 是否启用 AEC
     * @param isUseAECM   是否使用 AECM
     */
    virtual void ConfigAEC(bool isEnableAEC, bool isUseAECM) = 0;
#ifdef _WIN32
	virtual bool ChangeMicrophone(const char *device) = 0;
	virtual bool ChangeSpeaker(const char *device) = 0;
#endif
};

class RtpToNtpEstimatorInterface
{
public:
	virtual bool UpdateMeasurements(int64_t system_ms, uint32_t rtp_timestamp) = 0;
	virtual bool Estimate(int64_t rtp_timestamp, int64_t *estimated_system_ms) = 0;
};

//BUTEL_VOICEENGINE_EXPORT

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#ifdef BUTEL_VOICEENGINE_EXPORT
#define BUTEL_VOE_API __declspec(dllexport)
#else
#define BUTEL_VOE_API __declspec(dllimport)
#endif
#else
#define BUTEL_VOE_API
#endif

BUTEL_VOE_API void SetButelVoiceEngineLog(LogFun debug, LogFun info, LogFun warrn, LogFun error);
BUTEL_VOE_API ButelVoiceEngineInterface* CreateButelVoiceEngine();
BUTEL_VOE_API void DestroyButelVoiceEngine(ButelVoiceEngineInterface *engine);
BUTEL_VOE_API uint32_t GetSSRC(const char *buffer);
BUTEL_VOE_API void SetSSRC(char *buffer, uint32_t ssrc);
#if defined(ANDROID) || defined(__ANDROID__)
BUTEL_VOE_API void ButelVOESetJVM(JavaVM* jvm);
#endif

BUTEL_VOE_API RtpToNtpEstimatorInterface *CreateRtpToNtpEstimator();
BUTEL_VOE_API void DestroyRtpToNtpEstimator(RtpToNtpEstimatorInterface **estimator);

#ifdef _WIN32
#include "MediaFrameworkDef.h"
BUTEL_VOE_API void SetConfigPath(char *configpath);
BUTEL_VOE_API int StartAudioCaptureTest_VOE(int samplerate, int channels, int bitspersample, char device[256], AudioCapTestDataCallback dataCallback, char audiofile[256]);
BUTEL_VOE_API int StopAudioCaptureTest_VOE();
BUTEL_VOE_API int StartAudioRenderTest_VOE(char device[256], char audiofile[256], AudioRenderPlayFinishCallback cb, void *ctx);
BUTEL_VOE_API int StopAudioRenderTest_VOE();
#endif

#ifdef __cplusplus
}
#endif

#endif
