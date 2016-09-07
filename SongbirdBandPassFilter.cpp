/*
  ==============================================================================

    SongbirdBandPassFilter.cpp
    Created: 16 Jul 2016 5:40:26pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "SongbirdBandPassFilter.h"

void SongbirdBandPassFilter::setup(double newSampleRate, double newFrequency, double newBandWidth, int gaindB) {
    
    sampleRate = newSampleRate;
    frequency = newFrequency;
    bandWidth = newBandWidth;
    
    lowPass.setup(FILTER_ORDER, sampleRate, frequency + bandWidth / 2);
    highPass.setup(FILTER_ORDER, sampleRate, frequency - bandWidth / 2);

    
    gainAbs = pow(10, gaindB / 20.0);
}

void SongbirdBandPassFilter::process(float* inSamples, int numSamples) {
    float** samplesPtrPtr {&inSamples};

    lowPass.process(numSamples, samplesPtrPtr);
    highPass.process(numSamples, samplesPtrPtr);
    
    // apply gain reduction
    std::transform(inSamples, &inSamples[numSamples-1], inSamples, std::bind1st(std::multiplies<double>(), gainAbs));
}

void SongbirdBandPassFilter::reset() {
    lowPass.reset();
    highPass.reset();
}

std::string SongbirdBandPassFilter::dump() {
    std::string output;
    
    output.append("gainAbs: ");
    output.append(std::to_string(gainAbs));
    output.append(" frequency: ");
    output.append(std::to_string(frequency));
    output.append(" bandWidth: ");
    output.append(std::to_string(bandWidth));
    output.append(" sampleRate: ");
    output.append(std::to_string(sampleRate));
    
    return output;
}