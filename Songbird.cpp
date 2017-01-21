/*
  ==============================================================================

    Songbird.cpp
    Created: 11 Jun 2016 7:49:09pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "Songbird.h"

Songbird::Songbird() :  mFilter() {
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

void Songbird::Process2in2out(float* inLeftSamples, float* inRightSamples, int numSamples) {
    
    std::vector<double> leftSamples(inLeftSamples, inLeftSamples + numSamples);
    std::vector<double> rightSamples(inRightSamples, inRightSamples + numSamples);
    
    mFilter.setModulation(mMOD.calcGainInLoop());
    
    mFilter.Process2in2out(&leftSamples[0], &rightSamples[0], numSamples);
    
    // call the LFO calcGain method to advance its internal counters manually
    // since were calling it once per buffer rather than once per sample
    // TODO: provide protection to make sure this is still effective for large
    // buffers
    for (size_t iii {0}; iii < numSamples - 1; iii++) {
        mMOD.calcGainInLoop();
    }
    
    std::copy(leftSamples.begin(), leftSamples.end(), inLeftSamples);
    std::copy(rightSamples.begin(), rightSamples.end(), inRightSamples);
}