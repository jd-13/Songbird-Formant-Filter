/*
 *	File:		SongbirdModulator.h
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

#include "ParameterData.h"
#include "RichterLFO/RichterLFO.h"
#include "WEFilters/AREnvelopeFollowerSquareLaw.h"
#include "WEFilters/ModulationSource.h"

class SongbirdModulator : public WECore::ModulationSource<double> {
public:
    SongbirdModulator() : _envelopeAmount(ENV1_AMOUNT.defaultValue) {}
    ~SongbirdModulator() override = default;

    WECore::Richter::RichterLFO MOD;
    WECore::AREnv::AREnvelopeFollowerSquareLaw ENV;

    void setSampleRate(double sampleRate);
    void setEnvelopeAmount(double val) { _envelopeAmount = ENV1_AMOUNT.BoundsCheck(val); }

private:
    double _envelopeAmount;

    double _getNextOutputImpl(double inSample) override;

    void _resetImpl() override;
};
