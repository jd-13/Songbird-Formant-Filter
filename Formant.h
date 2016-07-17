/*
  ==============================================================================

    Formant.h
    Created: 16 Jul 2016 6:05:47pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef FORMANT_H_INCLUDED
#define FORMANT_H_INCLUDED

// simple class to hold the data about an individual formant
class Formant {
public:
    Formant(int newFreq,
            int newGaindB,
            int newBandWidth) : frequency(newFreq),
    gaindB(newGaindB),
    bandWidth(newBandWidth) {}
    
    int frequency;
    int gaindB;
    int bandWidth;
};

#endif  // FORMANT_H_INCLUDED
