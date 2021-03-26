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

    registerParameter(vowel1, VOWEL1_STR, &SP::VOWEL, SP::VOWEL.VOWEL_A, [&](int val) { setVowel1(val); });
    registerParameter(vowel2, VOWEL2_STR, &SP::VOWEL, SP::VOWEL.VOWEL_E, [&](int val) { setVowel2(val); });
    registerParameter(filterPosition, FILTER_POSITION_STR, &SP::FILTER_POSITION, SP::FILTER_POSITION.defaultValue, PRECISION, [&](float val) { setFilterPosition(val); });
    registerParameter(mix, MIX_STR, &SP::MIX, SP::MIX.defaultValue, PRECISION, [&](float val) { setMix(val); });
    registerParameter(modMode, MODMODE_STR, SP::MODMODE_DEFAULT, [&](bool val) { setModMode(val); });

    registerParameter(phaseSyncMOD1, PHASESYNCMOD1_STR, RP::PHASESYNC_DEFAULT, [&](bool val) { setPhaseSyncMOD1(val); });
    registerParameter(tempoSyncMOD1, TEMPOSYNCMOD1_STR, RP::TEMPOSYNC_DEFAULT, [&](bool val) { setTempoSyncMOD1(val); });
    registerParameter(waveMOD1, WAVEMOD1_STR, &RP::WAVE, RP::WAVE.defaultValue, [&](int val) { setWaveMOD1(val); });
    registerParameter(depthMOD1, DEPTHMOD1_STR, &RP::DEPTH, 0, PRECISION, [&](float val) { setDepthMOD1(val); });
    registerParameter(freqMOD1, FREQMOD1_STR, &RP::FREQ, RP::FREQ.defaultValue, PRECISION, [&](float val) { setFreqMOD1(val); });
    registerParameter(phaseMOD1, PHASEMOD1_STR, &RP::PHASE, RP::PHASE.defaultValue, PRECISION, [&](float val) { setPhaseMOD1(val); });
    registerParameter(tempoNumerMOD1, TEMPONUMERMOD1_STR, &RP::TEMPONUMER, RP::TEMPONUMER.defaultValue, [&](int val) { setTempoNumerMOD1(val); });
    registerParameter(tempoDenomMOD1, TEMPODENOMMOD1_STR, &RP::TEMPODENOM, RP::TEMPODENOM.defaultValue, [&](int val) { setTempoDenomMOD1(val); });

    registerParameter(outputGain, OUTPUTGAIN_STR, &SP::OUTPUTGAIN, SP::OUTPUTGAIN.defaultValue, PRECISION, [&](float val) { setOutputGain(val); });

    // New parameters must be registered last to maintain backwards compatibility during setStateInformation
    registerParameter(invertMOD1, INVERTMOD1_STR, RP::INVERT_DEFAULT, [&](bool val) { setInvertMOD1(val); });

    registerParameter(attackENV1, ATTACKENV1_STR, &AP::ATTACK_MS, AP::ATTACK_MS.defaultValue, PRECISION, [&](float val) { setAttackENV1(val); });
    registerParameter(releaseENV1, RELEASEENV1_STR, &AP::RELEASE_MS, AP::RELEASE_MS.defaultValue, PRECISION, [&](float val) { setReleaseENV1(val); });
    registerParameter(amountENV1, AMOUNTENV1_STR, &ENV1_AMOUNT, ENV1_AMOUNT.defaultValue, PRECISION, [&](float val) { setAmountENV1(val); });

    registerParameter(airGain, AIR_STR, &SP::AIR_GAIN, SP::AIR_GAIN.defaultValue, PRECISION, [&](float val) { setAirGain(val); });
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
void SongbirdAudioProcessor::setVowel1(int val) {
    mSongbird.mFilter.setVowel1(val);
    vowel1->setValueNotifyingHost(vowel1->getNormalisableRange().convertTo0to1(val));
}

void SongbirdAudioProcessor::setVowel2(int val) {
    mSongbird.mFilter.setVowel2(val);
    vowel2->setValueNotifyingHost(vowel2->getNormalisableRange().convertTo0to1(val));
}

void SongbirdAudioProcessor::setFilterPosition(float val) {
    mSongbird.mFilter.setFilterPosition(WECore::Songbird::Parameters::FILTER_POSITION.NormalisedToInternal(val));
    filterPosition->setValueNotifyingHost(val);
}

void SongbirdAudioProcessor::setMix(float val) {
    mSongbird.mFilter.setMix(WECore::Songbird::Parameters::MIX.NormalisedToInternal(val));
    mix->setValueNotifyingHost(val);
}

void SongbirdAudioProcessor::setModMode(bool val) {
    mSongbird.mFilter.setModMode(val);
    modMode->setValueNotifyingHost(val);
}

void SongbirdAudioProcessor::setAirGain(float val) {
    mSongbird.mFilter.setAirGain(val);
    airGain->setValueNotifyingHost(val);
}

void SongbirdAudioProcessor::setOutputGain(float val) {
    mSongbird.mFilter.setOutputGain(WECore::Songbird::Parameters::OUTPUTGAIN.NormalisedToInternal(val));
    outputGain->setValueNotifyingHost(val);
}

void SongbirdAudioProcessor::setPhaseSyncMOD1(bool val) {
    mSongbird.mModulator->MOD.setPhaseSyncSwitch(val);
    phaseSyncMOD1->setValueNotifyingHost(val);
}

void SongbirdAudioProcessor::setTempoSyncMOD1(bool val) {
    mSongbird.mModulator->MOD.setTempoSyncSwitch(val);
    tempoSyncMOD1->setValueNotifyingHost(val);
}

void SongbirdAudioProcessor::setInvertMOD1(bool val) {
    mSongbird.mModulator->MOD.setInvertSwitch(val);
    invertMOD1->setValueNotifyingHost(val);
}

void SongbirdAudioProcessor::setWaveMOD1(int val) {
    mSongbird.mModulator->MOD.setWave(val);
    waveMOD1->setValueNotifyingHost(waveMOD1->getNormalisableRange().convertTo0to1(val));
}

void SongbirdAudioProcessor::setDepthMOD1(float val) {
    mSongbird.mModulator->MOD.setDepth(WECore::Richter::Parameters::DEPTH.NormalisedToInternal(val));
    depthMOD1->setValueNotifyingHost(val);
}

void SongbirdAudioProcessor::setFreqMOD1(float val) {
    mSongbird.mModulator->MOD.setFreq(WECore::Richter::Parameters::FREQ.NormalisedToInternal(val));
    freqMOD1->setValueNotifyingHost(val);
}

void SongbirdAudioProcessor::setPhaseMOD1(float val) {
    mSongbird.mModulator->MOD.setManualPhase(WECore::Richter::Parameters::PHASE.NormalisedToInternal(val));
    phaseMOD1->setValueNotifyingHost(val);
}

void SongbirdAudioProcessor::setTempoNumerMOD1(int val) {
    mSongbird.mModulator->MOD.setTempoNumer(val);
    tempoNumerMOD1->setValueNotifyingHost(tempoNumerMOD1->getNormalisableRange().convertTo0to1(val));
}

void SongbirdAudioProcessor::setTempoDenomMOD1(int val) {
    mSongbird.mModulator->MOD.setTempoDenom(val);
    tempoDenomMOD1->setValueNotifyingHost(tempoDenomMOD1->getNormalisableRange().convertTo0to1(val));
}

void SongbirdAudioProcessor::setAttackENV1(float val) {
    mSongbird.mModulator->ENV.setAttackTimeMs(WECore::AREnv::Parameters::ATTACK_MS.NormalisedToInternal(val));
    attackENV1->setValueNotifyingHost(val);
}

void SongbirdAudioProcessor::setReleaseENV1(float val) {
    mSongbird.mModulator->ENV.setReleaseTimeMs(WECore::AREnv::Parameters::RELEASE_MS.NormalisedToInternal(val));
    releaseENV1->setValueNotifyingHost(val);
}

void SongbirdAudioProcessor::setAmountENV1(float val) {
    mSongbird.mModulator->setEnvelopeAmount(ENV1_AMOUNT.NormalisedToInternal(val));
    amountENV1->setValueNotifyingHost(val);
}

std::vector<juce::String> SongbirdAudioProcessor::_provideParamNamesForMigration() {
    return std::vector<juce::String> {
        VOWEL1_STR,
        VOWEL2_STR,
        FILTER_POSITION_STR,
        MIX_STR,
        MODMODE_STR,

        PHASESYNCMOD1_STR,
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
        INVERTMOD1_STR,

        paramValues[15] = AP::ATTACK_MS.NormalisedToInternal(paramValues[15]);
        paramValues[16] = AP::RELEASE_MS.NormalisedToInternal(paramValues[16]);
        paramValues[17] = ENV1_AMOUNT.NormalisedToInternal(paramValues[17]);
        paramValues[18] = SP::AIR_GAIN.NormalisedToInternal(paramValues[18]);
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SongbirdAudioProcessor();
}
