/*
 *	File:		SongbirdModulator.cpp
 *
 *	Version:	1.0.0
 *
 *	Created:	23/11/2020
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

#pragma once

#include "SongbirdModulator.h"

void SongbirdModulator::setSampleRate(double sampleRate) {
    ENV.setSampleRate(sampleRate);
}

double SongbirdModulator::_getNextOutputImpl(double inSample) {
    return MOD.getNextOutput(0) / 2 + ENV.getNextOutput(inSample) * _envelopeAmount;
}

void SongbirdModulator::_resetImpl() {
    MOD.reset();
    ENV.reset();
}