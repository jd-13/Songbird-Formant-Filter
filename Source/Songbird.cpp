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
    mENV.reset();
}

void Songbird::Process1in1out(float* inSamples, int numSamples) {

    mFilter.setModulation(_getModulationValue(inSamples[0]));

    mFilter.Process1in1out(inSamples, numSamples);

    _advanceModulationState(&inSamples[1], numSamples - 1);
}

void Songbird::Process1in2out(float* inLeftSamples, float* inRightSamples, int numSamples) {

    mFilter.setModulation(_getModulationValue(inLeftSamples[0]));

    mFilter.Process1in1out(inLeftSamples, numSamples);

    _advanceModulationState(&inLeftSamples[1], numSamples - 1);

    // Copy the left buffer into the right, so that we have mono to stereo
    std::copy(inLeftSamples, inLeftSamples + numSamples, inRightSamples);
}

void Songbird::Process2in2out(float* inLeftSamples, float* inRightSamples, int numSamples) {

    mFilter.setModulation(_getModulationValue((inLeftSamples[0] + inRightSamples[0]) / 2));

    mFilter.Process2in2out(inLeftSamples, inRightSamples, numSamples);

    _advanceModulationState(inLeftSamples, inRightSamples, numSamples - 1);
}

double Songbird::_getModulationValue(float inSample) {
    return mMOD.getNextOutput(0) + mENV.getNextOutput(inSample) * _envelopeAmount;
}

void Songbird::_advanceModulationState(float* inSamples, int numSamples) {

    // Stop one short of numSteps, we'll call calcGainInLoop once more to cache the last output
    for (int iii {0}; iii < numSamples - 1; iii++) {
        mMOD.getNextOutput(0);
        mENV.getNextOutput(inSamples[iii]);
    }

    // Cache the last mod output from this buffer
    _lastModOutput = _getModulationValue(inSamples[numSamples - 1]);
}

void Songbird::_advanceModulationState(float* inLeftSamples,
                                       float* inRightSamples,
                                       int numSamples) {
    // Stop one short of numSteps, we'll call calcGainInLoop once more to cache the last output
    for (int iii {0}; iii < numSamples - 1; iii++) {
        mMOD.getNextOutput(0);
        mENV.getNextOutput((inLeftSamples[iii] + inRightSamples[iii]) / 2);
    }

    // Cache the last mod output from this buffer
    _lastModOutput = _getModulationValue((inLeftSamples[numSamples - 1] + inRightSamples[numSamples - 1]) / 2);
;
}
