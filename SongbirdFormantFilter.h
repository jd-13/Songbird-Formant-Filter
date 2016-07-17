/*
  ==============================================================================

    SongbirdFormantFilter.h
    Created: 16 Jul 2016 5:58:00pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef SONGBIRDFORMANTFILTER_H_INCLUDED
#define SONGBIRDFORMANTFILTER_H_INCLUDED

#include "Formant.h"
#include "SongbirdBandPassFilter.h"

// a class containing a vector of bandpass filters 
class SongbirdFormantFilter {
public:
    SongbirdFormantFilter(int numFormants = 5);
    
    void process(std::vector<float>& samples);
    
    bool setFormants(std::vector<Formant> formants, double sampleRate);
    
    void reset();
    
private:
    std::vector<SongbirdBandPassFilter> filters;
};



#endif  // SONGBIRDFORMANTFILTER_H_INCLUDED
