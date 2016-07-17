/*
  ==============================================================================

    Songbird.cpp
    Created: 11 Jun 2016 7:49:09pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "Songbird.h"

Songbird::Songbird() : mFilter() {
    mFilter.setVowel1(VOWEL_A);
    //mFilter.setVowel2(VOWEL_E);
    
}

Songbird::~Songbird() {
    
}

void Songbird::setSampleRate(double sampleRate) {
    mFilter.setSampleRate(sampleRate);
}

void Songbird::reset() {
    mFilter.reset();
}

void Songbird::Process2in2out(float *leftSamples, float *rightSamples, int numSamples) {
    mFilter.Process2in2out(leftSamples, rightSamples, numSamples);
}