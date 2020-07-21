/*
 *	File:		ParameterData.h
 *
 *	Version:	1.0.0
 *
 *	Created:	12/06/2016
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

#ifndef PARAMETERDATA_H_INCLUDED
#define PARAMETERDATA_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "General/ParameterDefinition.h"

// This exists to provide the conversion for the decimal readout
const ParameterDefinition::RangedParameter<double> PHASE_DISPLAY(0, 360, 0);

const String    VOWEL1_STR {"Vowel1"},
                VOWEL2_STR {"Vowel2"},
                FILTER_POSITION_STR {"Position"},
                MIX_STR {"Mix"},
                MODMODE_STR {"ModMode"},
                OUTPUTGAIN_STR {"OutputGain"},

                PHASESYNCMOD1_STR {"MOD1PhaseSync"},
                PHASEMOD1_STR {"MOD1Phase"},
                TEMPOSYNCMOD1_STR {"MOD1TempoSync"},
                WAVEMOD1_STR {"MOD1Wave"},
                DEPTHMOD1_STR {"MOD1Depth"},
                FREQMOD1_STR {"MOD1Frequency"},
                TEMPONUMERMOD1_STR {"MOD1TempoNumerator"},
                TEMPODENOMMOD1_STR {"MOD1TempoDenominator"},
                GROUP_MOD1 {"MOD1"};

#endif  // PARAMETERDATA_H_INCLUDED
