/*
 *	File:		Songbird.cpp
 *
 *	Version:	1.0.0
 *
 *	Created:	11/06/2016
 *
 *	This file is part of Songbird.
 *
 *  Songbird is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Songbird is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Songbird.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "Songbird.h"

void Songbird::setSampleRate(double sampleRate) {
    mFilter.setSampleRate(sampleRate);
}

void Songbird::reset() {
    mFilter.reset();
    mMOD.reset();
}

void Songbird::Process1in1out(float* inSamples, int numSamples) {

    // Hack, to be fixed soon.
    // We don't have a proper 1-in-1-out method so use a 2-in-2out with an empty right channel
    std::vector<float> emptySamples(numSamples);
    
    mFilter.setModulation(mMOD.calcGainInLoop());
    
    mFilter.Process2in2out(inSamples, &emptySamples[0], numSamples);
    
    // call the LFO calcGain method to advance its internal counters manually
    // since were calling it once per buffer rather than once per sample
    // TODO: provide protection to make sure this is still effective for large
    // buffers
    for (size_t iii {0}; iii < numSamples - 1; iii++) {
        mMOD.calcGainInLoop();
    }
}

void Songbird::Process1in2out(float* inLeftSamples, float* inRightSamples, int numSamples) {
    
    mFilter.setModulation(mMOD.calcGainInLoop());
    
    mFilter.Process2in2out(inLeftSamples, inRightSamples, numSamples);
    
    // call the LFO calcGain method to advance its internal counters manually
    // since were calling it once per buffer rather than once per sample
    // TODO: provide protection to make sure this is still effective for large
    // buffers
    for (size_t iii {0}; iii < numSamples - 1; iii++) {
        mMOD.calcGainInLoop();
    }
    
    // Copy the left buffer into the right, so that we have mono to stereo
    std::copy(inLeftSamples, inLeftSamples + numSamples, inRightSamples);
}

void Songbird::Process2in2out(float* inLeftSamples, float* inRightSamples, int numSamples) {

    mFilter.setModulation(mMOD.calcGainInLoop());
    
    mFilter.Process2in2out(inLeftSamples, inRightSamples, numSamples);
    
    // call the LFO calcGain method to advance its internal counters manually
    // since were calling it once per buffer rather than once per sample
    // TODO: provide protection to make sure this is still effective for large
    // buffers
    for (size_t iii {0}; iii < numSamples - 1; iii++) {
        mMOD.calcGainInLoop();
    }
}
