/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "ParameterData.h"


//==============================================================================
SongbirdAudioProcessor::SongbirdAudioProcessor()
{
    namespace SP = WECore::Songbird::Parameters;
    namespace RP = WECore::Richter::Parameters;
    namespace AP = WECore::AREnv::Parameters;

    // Set defaults
    mSongbird.mFilter.setVowel1(SP::VOWEL.VOWEL_A);
    mSongbird.mFilter.setVowel2(SP::VOWEL.VOWEL_E);
    mSongbird.mModulator->MOD.setDepth(0);

    mSongbird.mModulator->MOD.setBypassSwitch(RP::LFOSWITCH_ON);

    constexpr float PRECISION {0.01f};

    registerParameter(vowel1, VOWEL1_STR, &SP::VOWEL, SP::VOWEL.VOWEL_A);
    registerParameter(vowel2, VOWEL2_STR, &SP::VOWEL, SP::VOWEL.VOWEL_E);
    registerParameter(filterPosition, FILTER_POSITION_STR, &SP::FILTER_POSITION, SP::FILTER_POSITION.defaultValue, PRECISION);
    registerParameter(mix, MIX_STR, &SP::MIX, SP::MIX.defaultValue, PRECISION);
    registerParameter(modMode, MODMODE_STR, SP::MODMODE_DEFAULT);
    registerParameter(airGain, AIR_STR, &SP::AIR_GAIN, SP::AIR_GAIN.defaultValue, PRECISION);

    registerParameter(tempoSyncMOD1, TEMPOSYNCMOD1_STR, RP::TEMPOSYNC_DEFAULT);
    registerParameter(invertMOD1, INVERTMOD1_STR, RP::INVERT_DEFAULT);
    registerParameter(waveMOD1, WAVEMOD1_STR, &RP::WAVE, RP::WAVE.defaultValue);
    registerParameter(depthMOD1, DEPTHMOD1_STR, &RP::DEPTH, 0, PRECISION);
    registerParameter(freqMOD1, FREQMOD1_STR, &RP::FREQ, RP::FREQ.defaultValue, PRECISION);
    registerParameter(phaseMOD1, PHASEMOD1_STR, &RP::PHASE, RP::PHASE.defaultValue, PRECISION);
    registerParameter(tempoNumerMOD1, TEMPONUMERMOD1_STR, &RP::TEMPONUMER, RP::TEMPONUMER.defaultValue);
    registerParameter(tempoDenomMOD1, TEMPODENOMMOD1_STR, &RP::TEMPODENOM, RP::TEMPODENOM.defaultValue);

    registerParameter(outputGain, OUTPUTGAIN_STR, &SP::OUTPUTGAIN, SP::OUTPUTGAIN.defaultValue, PRECISION);

    registerParameter(attackENV1, ATTACKENV1_STR, &AP::ATTACK_MS, AP::ATTACK_MS.defaultValue, PRECISION);
    registerParameter(releaseENV1, RELEASEENV1_STR, &AP::RELEASE_MS, AP::RELEASE_MS.defaultValue, PRECISION);
    registerParameter(amountENV1, AMOUNTENV1_STR, &ENV1_AMOUNT, ENV1_AMOUNT.defaultValue, PRECISION);
}

SongbirdAudioProcessor::~SongbirdAudioProcessor()
{
}

//==============================================================================
const String SongbirdAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SongbirdAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SongbirdAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double SongbirdAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SongbirdAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SongbirdAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SongbirdAudioProcessor::setCurrentProgram (int index)
{
}

const String SongbirdAudioProcessor::getProgramName (int index)
{
    return String();
}

void SongbirdAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SongbirdAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    mSongbird.reset();
    mSongbird.setSampleRate(getSampleRate());
}

void SongbirdAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SongbirdAudioProcessor::setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet)
{
    // Reject any bus arrangements that are not compatible with your plugin

    const int numChannels = preferredSet.size();

   #if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
   #elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
   #else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! AudioProcessor::setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
   #endif

    return AudioProcessor::setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void SongbirdAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i) {
        buffer.clear (i, 0, buffer.getNumSamples());
    }

    juce::AudioPlayHead::CurrentPositionInfo mTempoInfo;
    getPlayHead()->getCurrentPosition(mTempoInfo);

    mSongbird.mModulator->MOD.prepareForNextBuffer(mTempoInfo.bpm, mTempoInfo.timeInSeconds);

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // TODO: this can be much better optimised, the 1in1out/1in2out configurations are still doing
    // all the work of the 2in2out configuration
    if (getNumOutputChannels() == 1 && getNumOutputChannels() == 1) {
        float* inSample {buffer.getWritePointer(0)};

        mSongbird.Process1in1out(inSample, buffer.getNumSamples());

    } else if (getNumInputChannels() == 1 && getNumOutputChannels() == 2) {
        float* inLeftSample {buffer.getWritePointer(0)};
        float* inRightSample {buffer.getWritePointer(1)};

        mSongbird.Process1in2out(inLeftSample, inLeftSample, buffer.getNumSamples());

        // copy the processed left channel over to the right
        std::copy(inLeftSample, inLeftSample + buffer.getNumSamples(), inRightSample);

    } else {
        float* inLeftSample {buffer.getWritePointer(0)};
        float* inRightSample {buffer.getWritePointer(1)};

        mSongbird.Process2in2out(inLeftSample, inRightSample, buffer.getNumSamples());
    }
}

//==============================================================================
bool SongbirdAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SongbirdAudioProcessor::createEditor()
{
    return new SongbirdAudioProcessorEditor (*this);
}

//==============================================================================
std::vector<juce::String> SongbirdAudioProcessor::_provideParamNamesForMigration() {
    return std::vector<juce::String> {
        VOWEL1_STR,
        VOWEL2_STR,
        FILTER_POSITION_STR,
        MIX_STR,
        MODMODE_STR,

        "REMOVED",
        TEMPOSYNCMOD1_STR,
        WAVEMOD1_STR,
        DEPTHMOD1_STR,
        FREQMOD1_STR,
        PHASEMOD1_STR,
        TEMPONUMERMOD1_STR,
        TEMPODENOMMOD1_STR,

        OUTPUTGAIN_STR,
        INVERTMOD1_STR,
        ATTACKENV1_STR,
        RELEASEENV1_STR,
        AMOUNTENV1_STR,
        AIR_STR
    };
}

void SongbirdAudioProcessor::_migrateParamValues(std::vector<float>& paramValues) {

    namespace SP = WECore::Songbird::Parameters;
    namespace RP = WECore::Richter::Parameters;
    namespace AP = WECore::AREnv::Parameters;

    if (paramValues.size() == 19) {
        paramValues[2] = SP::FILTER_POSITION.NormalisedToInternal(paramValues[2]);
        paramValues[3] = SP::MIX.NormalisedToInternal(paramValues[3]);
        paramValues[8] = RP::DEPTH.NormalisedToInternal(paramValues[8]);
        paramValues[9] = RP::FREQ.NormalisedToInternal(paramValues[9]);
        paramValues[10] = RP::PHASE.NormalisedToInternal(paramValues[10]);
        paramValues[13] = SP::OUTPUTGAIN.NormalisedToInternal(paramValues[13]);

        paramValues[15] = AP::ATTACK_MS.NormalisedToInternal(paramValues[15]);
        paramValues[16] = AP::RELEASE_MS.NormalisedToInternal(paramValues[16]);
        paramValues[17] = ENV1_AMOUNT.NormalisedToInternal(paramValues[17]);
        paramValues[18] = SP::AIR_GAIN.NormalisedToInternal(paramValues[18]);
    }
}

void SongbirdAudioProcessor::_onParameterUpdate() {
    mSongbird.mFilter.setVowel1(vowel1->get());
    mSongbird.mFilter.setVowel2(vowel2->get());
    mSongbird.mFilter.setFilterPosition(filterPosition->get());
    mSongbird.mFilter.setMix(mix->get());
    mSongbird.mFilter.setModMode(modMode->get());
    mSongbird.mFilter.setAirGain(airGain->get());
    mSongbird.mFilter.setOutputGain(outputGain->get());

    mSongbird.mModulator->MOD.setTempoSyncSwitch(tempoSyncMOD1->get());
    mSongbird.mModulator->MOD.setInvertSwitch(invertMOD1->get());
    mSongbird.mModulator->MOD.setWave(waveMOD1->get());
    mSongbird.mModulator->MOD.setDepth(depthMOD1->get());
    mSongbird.mModulator->MOD.setFreq(freqMOD1->get());
    mSongbird.mModulator->MOD.setManualPhase(phaseMOD1->get());
    mSongbird.mModulator->MOD.setTempoNumer(tempoNumerMOD1->get());
    mSongbird.mModulator->MOD.setTempoDenom(tempoDenomMOD1->get());

    mSongbird.mModulator->ENV.setAttackTimeMs(attackENV1->get());
    mSongbird.mModulator->ENV.setReleaseTimeMs(releaseENV1->get());
    mSongbird.mModulator->setEnvelopeAmount(amountENV1->get());
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SongbirdAudioProcessor();
}
