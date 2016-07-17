/*
  ==============================================================================

    SongbirdBandPassFilter.h
    Created: 16 Jul 2016 5:40:26pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef SONGBIRDBANDPASSFILTER_H_INCLUDED
#define SONGBIRDBANDPASSFILTER_H_INCLUDED

#include "ParameterData.h"
#include "DspFilters/Butterworth.h"

// an individual band pass filter, with built in gain
class SongbirdBandPassFilter {
public:
    
    SongbirdBandPassFilter() : lowPass(), highPass(), gainAbs(1) {}
    
    void setup(double sampleRate, double frequency, double bandWidth, int gaindB);
    
    void process(std::vector<float>& samples);
        
    void reset();
    
private:
    Dsp::SimpleFilter<Dsp::Butterworth::LowPass<FILTER_ORDER>, 1> lowPass;
    Dsp::SimpleFilter<Dsp::Butterworth::HighPass<FILTER_ORDER>, 1> highPass;
    
    float gainAbs;
};



#endif  // SONGBIRDBANDPASSFILTER_H_INCLUDED
