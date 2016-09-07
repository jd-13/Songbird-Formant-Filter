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
        SongbirdBandPassFilter* tempFilter = new SongbirdBandPassFilter();
        filters.push_back(tempFilter);
    }
}

SongbirdFormantFilter::~SongbirdFormantFilter() {
    for (size_t iii {0}; iii < filters.size(); iii++) {
        SongbirdBandPassFilter* tempFilter {filters[iii]};
        delete tempFilter;
    }
}

void SongbirdFormantFilter::process(float* inSamples, int numSamples) {
    if (numSamples > 0 && inSamples != nullptr) {
        
        // initialise the empty output buffer
        std::vector<float> outputBuffer(numSamples, 0);
                
        // perform the filtering for each formant peak
        for (size_t iii {0}; iii < filters.size(); iii++) {
            // copy the input samples to a new buffer
            std::vector<float> tempBuffer(inSamples, inSamples + numSamples);
            
            filters[iii]->process(&tempBuffer[0], numSamples);
            
            // add the processed samples to the output buffer
            for (size_t jjj {0}; jjj < tempBuffer.size(); jjj++) {
                outputBuffer[jjj] += tempBuffer[jjj];
            }
        }
        
        // write the buffer to output
        for (int iii {0}; iii < numSamples; iii++) {
            inSamples[iii] = outputBuffer[iii];
        }
    }
}

bool SongbirdFormantFilter::setFormants(std::vector<Formant> formants, double sampleRate) {
    bool retVal {false};
    
    // if the correct number of formants have been supplied,
    // apply them to each filter in turn
    if (filters.size() == formants.size()) {
        retVal = true;
        
        for (size_t iii {0}; iii < filters.size(); iii++) {
            filters[iii]->setup(sampleRate,
                                formants[iii].frequency,
                                formants[iii].bandWidth,
                                formants[iii].gaindB);
        }
    } else {
        Logger::outputDebugString("Incorrect size array of formants - cannot setup filters");
    }
    
    return retVal;
}

void SongbirdFormantFilter::reset() {
    for (SongbirdBandPassFilter* filter : filters) {
        filter->reset();
    }
}