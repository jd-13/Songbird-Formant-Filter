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
    mSongbird.mFilter.setVowel1(VOWEL1_DEFAULT);
    mSongbird.mFilter.setVowel2(VOWEL2_DEFAULT);
    mSongbird.mFilter.setFilterPosition(FILTER_POSITION_DEFAULT);
    mSongbird.mFilter.setMix(MIX_DEFAULT);
    
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
            return mSongbird.mFilter.getFilterPosition();
            
        case mix:
            return mSongbird.mFilter.getMix();
                        
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
            mSongbird.mFilter.setFilterPosition(TranslateParam_Norm2Inter(newValue, FILTER_POSITION_MIN, FILTER_POSITION_MAX));
            break;
            
        case mix:
            mSongbird.mFilter.setMix(TranslateParam_Norm2Inter(newValue, MIX_MIN, MIX_MAX));
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
            return String(mSongbird.mFilter.getFilterPosition());
            
        case mix:
            return String(mSongbird.mFilter.getMix());
            
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
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    if (getNumOutputChannels() == 1 && getNumOutputChannels() == 1) {
        
        /*float* inSample {buffer.getWritePointer(0)};
        mCarve.Process1in1out(inSample, buffer.getNumSamples());*/
        
    } else if (getNumInputChannels() == 1 && getNumOutputChannels() == 2) {
        
        /*float* inLeftSample {buffer.getWritePointer(0)};
        float* inRightSample {buffer.getWritePointer(1)};
        
        mCarve.Process1in2out(inLeftSample, inRightSample, buffer.getNumSamples());*/
        
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
