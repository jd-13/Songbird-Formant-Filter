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
#include "RichterMOD.h"
#include "ParameterData.h"

class Songbird {
public:
    Songbird();
    ~Songbird();
    
    SongbirdFilterModule mFilter;
    RichterMOD mMOD;
    
    void setSampleRate(double sampleRate);
    void reset();
    
    void Process2in2out(float* leftSamples, float* rightSamples, int numSamples);
    
};



#endif  // SONGBIRD_H_INCLUDED
