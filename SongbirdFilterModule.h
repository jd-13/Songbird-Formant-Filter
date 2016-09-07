/*
  ==============================================================================

    SongbirdFilterModule.h
    Created: 12 Jun 2016 7:25:17pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef SONGBIRDFILTER_H_INCLUDED
#define SONGBIRDFILTER_H_INCLUDED

#include "ParameterData.h"
#include "SongbirdFormantFilter.h"
#include <map>

static const int NUM_FORMANTS_PER_VOWEL {5};
static const int NUM_VOWELS {5};

enum class Channels {
    LEFT,
    RIGHT
};

// a set of 5 pairs of filters for vowel 1, and another set for vowel 2
class SongbirdFilterModule {
public:
    SongbirdFilterModule();
    
    void setVowel1(int val);
    void setVowel2(int val);
    void setFilterPosition(float val);
    void setSampleRate(float val);
    void setMix(float val);
    void reset();
    
    int getVowel1();
    int getVowel2();
    float getFilterPosition();
    float getMix();
    
    void Process2in2out(float* leftSamples, float* rightSamples, int numSamples);
    
private:
    template<typename T>
    T boundsCheck(T param, T min, T max) {
        if (param < min) param = min;
        if (param > max) param = max;
        
        return param;
    }
    
    int vowel1;
    int vowel2;
    float filterPosition;
    float sampleRate;
    float mix;
    
    std::map<Channels, SongbirdFormantFilter> filters1;
    std::map<Channels, SongbirdFormantFilter> filters2;
    
    static const Formant allFormants[NUM_VOWELS][NUM_FORMANTS_PER_VOWEL];
};

#endif  // SONGBIRDFILTER_H_INCLUDED
