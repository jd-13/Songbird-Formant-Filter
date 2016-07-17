/*
  ==============================================================================

    SongbirdBandPassFilter.cpp
    Created: 16 Jul 2016 5:40:26pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "SongbirdBandPassFilter.h"

void SongbirdBandPassFilter::setup(double sampleRate, double frequency, double bandWidth, int gaindB) {
    lowPass.setup(FILTER_ORDER, sampleRate, frequency + bandWidth / 2);
    highPass.setup(FILTER_ORDER, sampleRate, frequency - bandWidth / 2);
    gainAbs = powf(10, gaindB / 20);
    
}

void SongbirdBandPassFilter::process(std::vector<float>& samples) {
    float* samplesPtr {&samples[0]};
    float** samplesPtrPtr {&samplesPtr};
    
    lowPass.process(samples.size(), samplesPtrPtr);
    highPass.process(samples.size(), samplesPtrPtr);
    
    // apply gain reduction
    std::transform(samples.begin(), samples.end(), samples.begin(), std::bind1st(std::multiplies<float>(), gainAbs));
}

void SongbirdBandPassFilter::reset() {
    lowPass.reset();
    highPass.reset();
}