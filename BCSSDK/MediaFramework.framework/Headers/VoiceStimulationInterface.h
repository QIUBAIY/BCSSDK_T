#ifndef VOICE_STIMULATION_INTERFACE_H
#define VOICE_STIMULATION_INTERFACE_H

#include <string>

class SpeakerChangeNotify
{
public:
	virtual ~SpeakerChangeNotify(){}
    virtual void OnSpeakerChange(std::string speaker) = 0;
};

class VoiceStimulationInterface
{
public:
	virtual ~VoiceStimulationInterface() {}
	virtual bool SetSpeakerChangeNotify(SpeakerChangeNotify* notify) = 0;
	virtual bool AddSpeaker(std::string speaker) = 0;
	virtual bool RemoveSpeaker(std::string speaker) = 0;
	virtual bool OnSpeakerAudioDB(std::string speaker, float db) = 0;
};

#ifdef __cplusplus
	#define VOICESTIMULATION_EXTERNC extern "C"
#else
	#define EXTERNC
#endif

#ifdef WIN32
#ifdef VOICESTIMULATION_BUILD
	#define VOICESTIMULATION_API VOICESTIMULATION_EXTERNC _declspec(dllexport)
#else
	#define VOICESTIMULATION_API VOICESTIMULATION_EXTERNC _declspec(dllimport)
#endif
#else
#define VOICESTIMULATION_API VOICESTIMULATION_EXTERNC
#endif

VOICESTIMULATION_API VoiceStimulationInterface* CreateVoiceStimulation();
VOICESTIMULATION_API void DestroyVoiceStimulation(VoiceStimulationInterface** inst);

#endif
