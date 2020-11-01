/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Songbird.h"
#include "CoreJUCEPlugin/CoreAudioProcessor.h"


//==============================================================================
/**
*/
class SongbirdAudioProcessor  : public WECore::JUCEPlugin::CoreAudioProcessor
{
public:
    //==============================================================================
    SongbirdAudioProcessor();
    ~SongbirdAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet) override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    double getLastLFOOutput() { return mSongbird.getLastLFOOutput(); }

    /**
     * Parameter setters.
     *
     * For float parameters a value in the normalised 0 to 1 range is expected.
     *
     * For int parameters are used to represent menu items, the integer value in the real range of
     * the parameter (eg. 0 to 4) is expected.
     *
     * For bool parameters they can only be true or false anyway.
     *
     * These do not call the ChangeBroadcaster as the UI will already know about these changes since
     * it is the only one calling these methods.
     */
    /** @{ */
    void setVowel1(int val);
    void setVowel2(int val);
    void setFilterPosition(float val);
    void setMix(float val);
    void setModMode(bool val);
    void setOutputGain(float val);

    void setPhaseSyncMOD1(bool val);
    void setTempoSyncMOD1(bool val);
    void setInvertMOD1(bool val);
    void setWaveMOD1(int val);
    void setDepthMOD1(float val);
    void setFreqMOD1(float val);
    void setPhaseMOD1(float val);
    void setTempoNumerMOD1(int val);
    void setTempoDenomMOD1(int val);
    /** @} */

    // Parameters (public for beginChangeGesture/endChangeGesture/get)
    AudioParameterInt* vowel1;
    AudioParameterInt* vowel2;
    AudioParameterFloat* filterPosition;
    AudioParameterFloat* mix;
    AudioParameterBool* modMode;
    AudioParameterFloat* outputGain;

    AudioParameterBool* phaseSyncMOD1;
    AudioParameterBool* tempoSyncMOD1;
    AudioParameterBool* invertMOD1;
    AudioParameterInt* waveMOD1;
    AudioParameterFloat* depthMOD1;
    AudioParameterFloat* freqMOD1;
    AudioParameterFloat* phaseMOD1;
    AudioParameterInt* tempoNumerMOD1;
    AudioParameterInt* tempoDenomMOD1;

private:
    Songbird mSongbird;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SongbirdAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
