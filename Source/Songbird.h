/*
 *	File:		Songbird.h
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

#ifndef SONGBIRD_H_INCLUDED
#define SONGBIRD_H_INCLUDED

#include "SongbirdFilters/SongbirdFilterModule.h"

#include "RichterLFO/RichterMOD.h"
#include "WEFilters/AREnvelopeFollowerSquareLaw.h"
#include "ParameterData.h"

class Songbird {
public:
    Songbird() : _lastModOutput(0), _envelopeAmount(ENV1_AMOUNT.defaultValue) {}
    ~Songbird() = default;

    WECore::Songbird::SongbirdFilterModule<float> mFilter;
    WECore::Richter::RichterMOD mMOD;
    WECore::AREnv::AREnvelopeFollowerSquareLaw mENV;

    void setSampleRate(double sampleRate);
    void setEnvelopeAmount(double val) { _envelopeAmount = val; }
    void reset();

    double getLastModOutput() const { return _lastModOutput; };

    void Process1in1out(float* inSamples, int numSamples);
    void Process1in2out(float* leftSamples, float* rightSamples, int numSamples);
    void Process2in2out(float* leftSamples, float* rightSamples, int numSamples);

private:
    double _lastModOutput;
    double _envelopeAmount;

    double _getModulationValue(float inSample);

    /**
     * This needs to be called once per buffer to advance the LFO's internal counters manually.
     *
     * TODO: provide protection to make sure this is still effective for large buffers.
     */
    /** @{ */
    void _advanceModulationState(float* inSamples, int numSamples);
    void _advanceModulationState(float* inLeftSamples, float* inRightSamples, int numSamples);
    /** @} */
};



#endif  // SONGBIRD_H_INCLUDED
