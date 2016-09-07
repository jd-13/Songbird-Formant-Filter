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
#include "DspFilters/Legendre.h"

// an individual band pass filter, with built in gain
class SongbirdBandPassFilter {
public:
    
    SongbirdBandPassFilter() : lowPass(), highPass(), gainAbs(1) {}
        
    void setup(double newSampleRate, double newFrequency, double newBandWidth, int gaindB);
    
    void process(float* inSamples, int numSamples);
        
    void reset();
    
    std::string dump();
    
private:
    Dsp::SimpleFilter<Dsp::Legendre::LowPass<FILTER_ORDER>, 1> lowPass;
    Dsp::SimpleFilter<Dsp::Legendre::HighPass<FILTER_ORDER>, 1> highPass;
    
    
    double gainAbs;
    
    // store these to allow easy debugging output
    double  sampleRate,
            frequency,
            bandWidth;
    
};





#endif  // SONGBIRDBANDPASSFILTER_H_INCLUDED
