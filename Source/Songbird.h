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
#include "WEFilters/SimpleCompressor.h"

#include "SongbirdModulator.h"

class Songbird {
public:
    Songbird();
    ~Songbird() = default;

    WECore::Songbird::SongbirdFilterModule<float> mFilter;
    std::shared_ptr<SongbirdModulator> mModulator;

    void setSampleRate(double sampleRate);
    void reset();

    void Process1in1out(float* inSamples, int numSamples);
    void Process1in2out(float* leftSamples, float* rightSamples, int numSamples);
    void Process2in2out(float* leftSamples, float* rightSamples, int numSamples);

private:
    // We use a compressor over the output to catch some of the more aggressive formant peaks
    WECore::SimpleCompressor::SimpleCompressor<float> _compressorLeft;
    WECore::SimpleCompressor::SimpleCompressor<float> _compressorRight;

};



#endif  // SONGBIRD_H_INCLUDED
