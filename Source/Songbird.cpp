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

Songbird::Songbird() {
    mModulator = std::make_shared<SongbirdModulator>();
    mFilter.setModulationSource(mModulator);

    // Set up the output limiter
    // This is tuned to catch peaks before they stray too far above 0dB
    // Compression starts at around -2dB at a very soft knee and limits approaching -0.3dB
    _compressorLeft.setDirection(WECore::SimpleCompressor::Direction::DOWNWARD);
    _compressorLeft.setAttack(2);
    _compressorLeft.setRelease(100);
    _compressorLeft.setThreshold(2);
    _compressorLeft.setRatio(8);
    _compressorLeft.setKneeWidth(6);

    _compressorRight.setDirection(WECore::SimpleCompressor::Direction::DOWNWARD);
    _compressorRight.setAttack(2);
    _compressorRight.setRelease(100);
    _compressorRight.setThreshold(2);
    _compressorRight.setRatio(8);
    _compressorRight.setKneeWidth(6);
}

void Songbird::setSampleRate(double sampleRate) {
    mFilter.setSampleRate(sampleRate);
    mModulator->setSampleRate(sampleRate);
    _compressorLeft.setSampleRate(sampleRate);
    _compressorRight.setSampleRate(sampleRate);
}

void Songbird::reset() {
    mFilter.reset();
    mModulator->reset();
    _compressorLeft.reset();
    _compressorRight.reset();
}

void Songbird::Process1in1out(float* inSamples, int numSamples) {

    mFilter.Process1in1out(inSamples, numSamples);

    _compressorLeft.process1in1out(inSamples, numSamples);
}

void Songbird::Process1in2out(float* inLeftSamples, float* inRightSamples, int numSamples) {

    mFilter.Process1in1out(inLeftSamples, numSamples);

    _compressorLeft.process1in1out(inLeftSamples, numSamples);

    // Copy the left buffer into the right, so that we have mono to stereo
    std::copy(inLeftSamples, inLeftSamples + numSamples, inRightSamples);
}

void Songbird::Process2in2out(float* inLeftSamples, float* inRightSamples, int numSamples) {

    mFilter.Process2in2out(inLeftSamples, inRightSamples, numSamples);

    _compressorLeft.process1in1out(inLeftSamples, numSamples);
    _compressorRight.process1in1out(inRightSamples, numSamples);
}

