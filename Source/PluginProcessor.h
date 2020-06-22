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

    int getNumParameters() override;
    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;

    const String getParameterName (int index) override;
    const String getParameterText (int index) override;

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
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    enum Parameters{
        vowel1 = 0,
        vowel2,
        filterPosition,
        mix,
        modMode,

        phaseSyncMOD1,
        tempoSyncMOD1,
        waveMOD1,
        depthMOD1,
        freqMOD1,
        phaseMOD1,
        tempoNumerMOD1,
        tempoDenomMOD1,

        outputGain,

        totalNumParams
    };

    double getLastLFOOutput() { return mSongbird.getLastLFOOutput(); }

private:
    Songbird mSongbird;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SongbirdAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
