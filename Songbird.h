/*
  ==============================================================================

    Songbird.h
    Created: 11 Jun 2016 7:49:09pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef SONGBIRD_H_INCLUDED
#define SONGBIRD_H_INCLUDED

#include "SongbirdFilters/SongbirdFilterModule.h"
#include "RichterLFO/RichterMOD.h"
#include "ParameterData.h"

class Songbird {
public:
    Songbird();
    ~Songbird() = default;
    
    SongbirdFilterModule mFilter;
    RichterMOD mMOD;
    
    void setSampleRate(double sampleRate);
    void reset();
    
    void Process1in1out(float* inSamples, int numSamples);
    void Process1in2out(float* leftSamples, float* rightSamples, int numSamples);
    void Process2in2out(float* leftSamples, float* rightSamples, int numSamples);
    
};



#endif  // SONGBIRD_H_INCLUDED
