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

double Songbird::getLastLFOOutput() const {
    return _lastLFOOutput;
}

void Songbird::Process1in1out(float* inSamples, int numSamples) {
    
    mFilter.setModulation(mMOD.calcGainInLoop());
    
    mFilter.Process1in1out(inSamples, numSamples);
    
    _advanceLFOState(numSamples - 1);
}

void Songbird::Process1in2out(float* inLeftSamples, float* inRightSamples, int numSamples) {
    
    mFilter.setModulation(mMOD.calcGainInLoop());
    
    mFilter.Process1in1out(inLeftSamples, numSamples);

    _advanceLFOState(numSamples - 1);
    
    // Copy the left buffer into the right, so that we have mono to stereo
    std::copy(inLeftSamples, inLeftSamples + numSamples, inRightSamples);
}

void Songbird::Process2in2out(float* inLeftSamples, float* inRightSamples, int numSamples) {

    mFilter.setModulation(mMOD.calcGainInLoop());
    
    mFilter.Process2in2out(inLeftSamples, inRightSamples, numSamples);

    _advanceLFOState(numSamples - 1);
}

void Songbird::_advanceLFOState(int numSteps) {
    
    // Stop one short of numSteps, we'll call calcGainInLoop once more to cache the last output
    for (int iii {0}; iii < numSteps - 1; iii++) {
        mMOD.calcGainInLoop();
    }
    
    // Cache the last LFO output from this buffer
    _lastLFOOutput = mMOD.calcGainInLoop();
}
