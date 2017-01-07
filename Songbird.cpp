/*
  ==============================================================================

    Songbird.cpp
    Created: 11 Jun 2016 7:49:09pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "Songbird.h"

Songbird::Songbird() :  mFilter(),
                        rawFilterPosition(FILTER_POSITION.defaultValue),
                        modMode(MODMODE_DEFAULT) {
}

Songbird::~Songbird() {
    
}

void Songbird::setSampleRate(double sampleRate) {
    mFilter.setSampleRate(sampleRate);
}

void Songbird::reset() {
    mFilter.reset();
    mMOD.reset();
}

void Songbird::Process2in2out(float *leftSamples, float *rightSamples, int numSamples) {
    
    if (modMode == MODMODE_BLEND) {
        mFilter.setFilterPosition(rawFilterPosition + mMOD.calcGainInLoop());
        mFilter.Process2in2out(leftSamples, rightSamples, numSamples);
    } else {
        mFilter.setFilterPosition(FILTER_POSITION.minValue);
        mFilter.setVowel1(calcModVowel());
        mFilter.Process2in2out(leftSamples, rightSamples, numSamples);
    }
    
    // call the LFO calcGain method to advance its internal counters manually
    // since were calling it once per buffer rather than once per sample
    // TODO: provide protection to make sure this is still effective for large
    // buffers
    for (size_t iii {0}; iii < numSamples - 1; iii++) {
        mMOD.calcGainInLoop();
    }
}

Vowel Songbird::calcModVowel() {
    // get the first and second vowels
    Vowel vowel1 {mFilter.getVowelDescription(mFilter.getVowel1())};
    Vowel vowel2 {mFilter.getVowelDescription(mFilter.getVowel2())};
    
    // set the frequency values
    Vowel retVal {vowel1};
    
    for (int iii {0}; iii < NUM_FORMANTS_PER_VOWEL; iii++) {
        retVal[iii].frequency = vowel1[iii].frequency;
        retVal[iii].frequency += std::fabs(vowel1[iii].frequency - vowel2[iii].frequency)
                                 * mMOD.calcGainInLoop();
        
        retVal[iii].gaindB = vowel1[iii].gaindB;
        retVal[iii].gaindB += std::fabs(vowel1[iii].gaindB - vowel2[iii].gaindB)
                              * mMOD.calcGainInLoop();
    }
    
    return retVal;
}