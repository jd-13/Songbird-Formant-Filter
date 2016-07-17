/*
  ==============================================================================

    Songbird.h
    Created: 11 Jun 2016 7:49:09pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef SONGBIRD_H_INCLUDED
#define SONGBIRD_H_INCLUDED

#include "SongbirdFilterModule.h"

class Songbird {
public:
    Songbird();
    ~Songbird();
    
    SongbirdFilterModule mFilter;
    
    void setSampleRate(double sampleRate);
    void reset();
    
    void Process2in2out(float* leftSamples, float* rightSamples, int numSamples);
    
private:
    
    
};



#endif  // SONGBIRD_H_INCLUDED
