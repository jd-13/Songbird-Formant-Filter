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
    double getLastModOutput() { return mSongbird.mModulator->getLastOutput(); }

    // Parameters (public for beginChangeGesture/endChangeGesture/get)
    AudioParameterInt* vowel1;
    AudioParameterInt* vowel2;
    AudioParameterFloat* filterPosition;
    AudioParameterFloat* mix;
    AudioParameterBool* modMode;
    AudioParameterFloat* airGain;
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

    AudioParameterFloat* attackENV1;
    AudioParameterFloat* releaseENV1;
    AudioParameterFloat* amountENV1;

private:
    Songbird mSongbird;

    std::vector<juce::String> _provideParamNamesForMigration() override;
    void _migrateParamValues(std::vector<float>& paramValues) override;

    void _onParameterUpdate() override;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SongbirdAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
