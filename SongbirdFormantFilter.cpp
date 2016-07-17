/*
  ==============================================================================

    SongbirdFormantFilter.cpp
    Created: 16 Jul 2016 5:58:00pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "SongbirdFormantFilter.h"

SongbirdFormantFilter::SongbirdFormantFilter(int numFormants) {
    // create and store the appropriate number of filters
    for (int iii {0}; iii < numFormants; iii++) {
        filters.push_back(SongbirdBandPassFilter());
    }
}

void SongbirdFormantFilter::process(std::vector<float> &samples) {
    // initialise the output buffer
    std::vector<float> outputBuffer(samples.size(), 0);
    
    // perform the filtering for each formant peak
    for (SongbirdBandPassFilter& filter : filters) {
        // copy the input samples to a new buffer
        std::vector<float> tempBuffer(samples);
        
        filter.process(tempBuffer);
        
        // add the processed samples to the output buffer
        for (size_t iii {0}; iii < tempBuffer.size(); iii++) {
            outputBuffer[iii] += tempBuffer[iii];
        }
    }
    
    // write the buffer to output
    samples = outputBuffer;
}

bool SongbirdFormantFilter::setFormants(std::vector<Formant> formants, double sampleRate) {
    bool retVal {false};
    
    // if the correct number of formants have been supplied,
    // apply them to each filter in turn
    if (filters.size() == formants.size()) {
        retVal = true;
        
        for (size_t iii {0}; iii < filters.size(); iii++) {
            filters[iii].setup(sampleRate,
                               formants[iii].frequency,
                               formants[iii].bandWidth,
                               formants[iii].gaindB);
        }
    }
    
    return retVal;
}

void SongbirdFormantFilter::reset() {
    for (SongbirdBandPassFilter& filter : filters) {
        filter.reset();
    }
}