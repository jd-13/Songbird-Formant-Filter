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
    mSongbird.mFilter.setVowel1(WECore::Songbird::Parameters::VOWEL.defaultValue);
    mSongbird.mFilter.setVowel2(WECore::Songbird::Parameters::VOWEL.defaultValue);
    mSongbird.mFilter.setFilterPosition(WECore::Songbird::Parameters::FILTER_POSITION.defaultValue);
    mSongbird.mFilter.setMix(WECore::Songbird::Parameters::MIX.defaultValue);
    mSongbird.mFilter.setFilterPosition(WECore::Songbird::Parameters::FILTER_POSITION.defaultValue);
    mSongbird.mFilter.setModMode(WECore::Songbird::Parameters::MODMODE_DEFAULT);
    
    mSongbird.mMOD.setBypassSwitch(WECore::Richter::Parameters::LFOSWITCH_ON);
    mSongbird.mMOD.setPhaseSyncSwitch(WECore::Richter::Parameters::PHASESYNC_DEFAULT);
    mSongbird.mMOD.setTempoSyncSwitch(WECore::Richter::Parameters::TEMPOSYNC_DEFAULT);
    mSongbird.mMOD.setWave(WECore::Richter::Parameters::WAVE.defaultValue);
    mSongbird.mMOD.setDepth(WECore::Richter::Parameters::DEPTH.defaultValue);
    mSongbird.mMOD.setFreq(WECore::Richter::Parameters::FREQ.defaultValue);
    mSongbird.mMOD.setManualPhase(WECore::Richter::Parameters::PHASE.defaultValue);
    mSongbird.mMOD.setTempoNumer(WECore::Richter::Parameters::TEMPONUMER.defaultValue);
    mSongbird.mMOD.setTempoDenom(WECore::Richter::Parameters::TEMPODENOM.defaultValue);
    
    UIUpdateFlag = true;
}

SongbirdAudioProcessor::~SongbirdAudioProcessor()
{
}

//==============================================================================
const String SongbirdAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int SongbirdAudioProcessor::getNumParameters()
{
    return totalNumParams;
}

float SongbirdAudioProcessor::getParameter(int index) {
    switch (index) {
        case vowel1:
            return mSongbird.mFilter.getVowel1();
            
        case vowel2:
            return mSongbird.mFilter.getVowel2();
            
        case filterPosition:
            return WECore::Songbird::Parameters::FILTER_POSITION.InteralToNormalised(mSongbird.mFilter.getFilterPosition());
            
        case mix:
            return WECore::Songbird::Parameters::MIX.InteralToNormalised(mSongbird.mFilter.getMix());
            
        case modMode:
            return mSongbird.mFilter.getModMode();
            
            

            
        case phaseSyncMOD1:
            return mSongbird.mMOD.getPhaseSyncSwitch();
            
        case tempoSyncMOD1:
            return mSongbird.mMOD.getTempoSyncSwitch();
            
        case waveMOD1:
            return mSongbird.mMOD.getWave();
            
        case depthMOD1:
            return WECore::Richter::Parameters::DEPTH.InteralToNormalised(mSongbird.mMOD.getDepth());
            
        case freqMOD1:
            return WECore::Richter::Parameters::FREQ.InteralToNormalised(mSongbird.mMOD.getFreq());
            
        case phaseMOD1:
            return WECore::Richter::Parameters::PHASE.InteralToNormalised(mSongbird.mMOD.getManualPhase());
            
        case tempoNumerMOD1:
            return mSongbird.mMOD.getTempoNumer();
            
        case tempoDenomMOD1:
            return mSongbird.mMOD.getTempoDenom();
            
            
        default:
            return 0.0f;
    }
}

void SongbirdAudioProcessor::setParameter(int index, float newValue) {
    switch (index) {
        case vowel1:
            mSongbird.mFilter.setVowel1(static_cast<int>(roundf(newValue)));
            break;
            
        case vowel2:
            mSongbird.mFilter.setVowel2(static_cast<int>(roundf(newValue)));
            break;
            
        case filterPosition:
            mSongbird.mFilter.setFilterPosition(WECore::Songbird::Parameters::FILTER_POSITION.NormalisedToInteral(newValue));
            break;
            
        case mix:
            mSongbird.mFilter.setMix(WECore::Songbird::Parameters::MIX.NormalisedToInteral(newValue));
            break;
            
        case modMode:
            mSongbird.mFilter.setModMode(newValue < 0.5);
            break;
            

            
        case phaseSyncMOD1:
            mSongbird.mMOD.setPhaseSyncSwitch(newValue < 0.5);
            break;
            
        case tempoSyncMOD1:
            mSongbird.mMOD.setTempoSyncSwitch(newValue < 0.5);
            break;
            
        case waveMOD1:
            mSongbird.mMOD.setWave(round(newValue));
            break;
            
        case depthMOD1:
            mSongbird.mMOD.setDepth(WECore::Richter::Parameters::DEPTH.NormalisedToInteral(newValue));
            break;
            
        case freqMOD1:
            mSongbird.mMOD.setFreq(WECore::Richter::Parameters::FREQ.NormalisedToInteral(newValue));
            break;
            
        case phaseMOD1:
            mSongbird.mMOD.setManualPhase(WECore::Richter::Parameters::PHASE.NormalisedToInteral(newValue));
            break;
            
        case tempoNumerMOD1:
            mSongbird.mMOD.setTempoNumer(newValue);
            break;
            
        case tempoDenomMOD1:
            mSongbird.mMOD.setTempoDenom(newValue);
            break;
            
            
        default:
            break;
    }
    UIUpdateFlag = true;
}

const String SongbirdAudioProcessor::getParameterName(int index) {
    switch (index) {
        case vowel1:
            return VOWEL1_STR;
            
        case vowel2:
            return VOWEL2_STR;
            
        case filterPosition:
            return FILTER_POSITION_STR;
            
        case mix:
            return MIX_STR;
            
        case modMode:
            return MODMODE_STR;
            

            
        case phaseSyncMOD1:
            return PHASESYNCMOD1_STR;
            
        case tempoSyncMOD1:
            return TEMPOSYNCMOD1_STR;
            
        case waveMOD1:
            return WAVEMOD1_STR;
            
        case depthMOD1:
            return DEPTHMOD1_STR;
            
        case freqMOD1:
            return FREQMOD1_STR;
            
        case phaseMOD1:
            return PHASEMOD1_STR;
            
        case tempoNumerMOD1:
            return TEMPONUMERMOD1_STR;
            
        case tempoDenomMOD1:
            return TEMPODENOMMOD1_STR;
            
        default:
            return String::empty;
    }
}

const String SongbirdAudioProcessor::getParameterText(int index)
{
    switch (index) {
        case vowel1:
            return String(mSongbird.mFilter.getVowel1());
            
        case vowel2:
            return String(mSongbird.mFilter.getVowel2());
            
        case filterPosition:
            return String(WECore::Songbird::Parameters::FILTER_POSITION.NormalisedToInteral(mSongbird.mFilter.getFilterPosition()));
            
        case mix:
            return String(WECore::Songbird::Parameters::MIX.NormalisedToInteral(mSongbird.mFilter.getMix()));
            
        case modMode:
            return String(static_cast<int>(mSongbird.mFilter.getModMode()));
            

            
        case phaseSyncMOD1:
            return String(static_cast<int>(mSongbird.mMOD.getPhaseSyncSwitch()));
            
        case tempoSyncMOD1:
            return String(static_cast<int>(mSongbird.mMOD.getTempoSyncSwitch()));
            
        case waveMOD1:
            return String(mSongbird.mMOD.getWave());
            
        case depthMOD1:
            return String(WECore::Richter::Parameters::DEPTH.InteralToNormalised(mSongbird.mMOD.getDepth()));
            
        case freqMOD1:
            return String(WECore::Richter::Parameters::FREQ.InteralToNormalised(mSongbird.mMOD.getFreq()));
            
        case phaseMOD1:
            return String(WECore::Richter::Parameters::PHASE.InteralToNormalised(mSongbird.mMOD.getManualPhase()));
            
        case tempoNumerMOD1:
            return String(mSongbird.mMOD.getTempoNumer());
            
        case tempoDenomMOD1:
            return String(mSongbird.mMOD.getTempoDenom());
            
        default:
            return String::empty;
    }
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
    
    mSongbird.mMOD.prepareForNextBuffer(mTempoInfo.bpm,
                                        mTempoInfo.timeInSeconds,
                                        getSampleRate());
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // TODO: this can be much better optimised, the 1in1out/1in2out configurations are still doing
    // all the work of the 2in2out configuration
    if (getNumOutputChannels() == 1 && getNumOutputChannels() == 1) {
        float* inSample {buffer.getWritePointer(0)};
        
        mSongbird.setSampleRate(getSampleRate());
        mSongbird.Process1in1out(inSample, buffer.getNumSamples());
        
    } else if (getNumInputChannels() == 1 && getNumOutputChannels() == 2) {
        float* inLeftSample {buffer.getWritePointer(0)};
        float* inRightSample {buffer.getWritePointer(1)};
        
        mSongbird.setSampleRate(getSampleRate());
        mSongbird.Process1in2out(inLeftSample, inLeftSample, buffer.getNumSamples());
        
        // copy the processed left channel over to the right
        std::copy(inLeftSample, inLeftSample + buffer.getNumSamples(), inRightSample);
        
    } else {
        float* inLeftSample {buffer.getWritePointer(0)};
        float* inRightSample {buffer.getWritePointer(1)};
        
        mSongbird.setSampleRate(getSampleRate());
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
void SongbirdAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    std::vector<float> userParams;
    for (int iii {0}; iii < totalNumParams; iii++) {
        userParams.push_back(getParameter(iii));
    }
    
    XmlElement root("Root");
    XmlElement *el = root.createNewChildElement("AllUserParam");
    
    el->addTextElement(String(floatVectorToString(userParams)));
    copyXmlToBinary(root, destData);
}

void SongbirdAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<XmlElement> pRoot(getXmlFromBinary(data, sizeInBytes));
    std::vector<float> tmpUserParam;
    
    if (pRoot != NULL) {
        forEachXmlChildElement((*pRoot), pChild) {
            if (pChild->hasTagName("AllUserParam")) {
                String sFloatCSV = pChild->getAllSubText();
                if (stringToFloatVector(sFloatCSV, tmpUserParam, totalNumParams) == totalNumParams) {
                    for (int iii {0}; iii < totalNumParams; iii++) {
                        setParameter(iii, tmpUserParam[iii]);
                    }
                }
            }
        }
        
        // Slightly hacky fix to prevent inverted button settings on startup
        setParameter(modMode, getParameter(modMode));
        
        setParameter(phaseSyncMOD1, getParameter(phaseSyncMOD1));
        setParameter(tempoSyncMOD1, getParameter(tempoSyncMOD1));
        
        
        UIUpdateFlag = true;
    }
}

String SongbirdAudioProcessor::floatVectorToString(const std::vector<float>& fData) const {
    String result {""};
    
    if (fData.size() < 1) {
        return result;
    }
    
    for (int iii {0}; iii < (fData.size() - 1); iii++) {
        result << String(fData[iii])<<",";
    }
    
    result << String(fData[fData.size() - 1]);
    
    return result;
}

int SongbirdAudioProcessor::stringToFloatVector(const String sFloatCSV, std::vector<float>& fData, int maxNumFloat) const {
    StringArray tokenizer;
    int tokenCount {tokenizer.addTokens(sFloatCSV, ",","")};
    int resultCount {(maxNumFloat <= tokenCount) ? maxNumFloat : tokenCount};
    
    for (int iii {0}; iii < resultCount; iii++) {
        fData.push_back(tokenizer[iii].getFloatValue());
    }
    
    return ((tokenCount <= maxNumFloat) ? resultCount : -1);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SongbirdAudioProcessor();
}
