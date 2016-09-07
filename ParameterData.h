/*
  ==============================================================================

    ParameterData.h
    Created: 12 Jun 2016 7:23:25pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef PARAMETERDATA_H_INCLUDED
#define PARAMETERDATA_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

const int   VOWEL_A {1},
            VOWEL_E {2},
            VOWEL_I {3},
            VOWEL_O {4},
            VOWEL_U {5},
            VOWEL1_DEFAULT {VOWEL_A},
            VOWEL2_DEFAULT {VOWEL_U},
            VOWEL_MIN {VOWEL_A},
            VOWEL_MAX {VOWEL_U};

const float FILTER_POSITION_DEFAULT {0.5},
            FILTER_POSITION_MIN {0},
            FILTER_POSITION_MAX {1},

            MIX_DEFAULT {1},
            MIX_MIN {0},
            MIX_MAX {1};

const String    VOWEL1_STR {"Vowel1"},
                VOWEL2_STR {"Vowel2"},
                FILTER_POSITION_STR {"Position"},
                MIX_STR {"Mix"};

const int FILTER_ORDER {8};

/* TranslateParam_Norm2Inter
 *
 * Translates parameter values from the normalised (0 to 1) range as required
 * by VSTs to the range used internally for that parameter
 *
 * args: val    Normalised value of the parameter
 *       min    The minimum value of the parameter, as specified above
 *       max    The maximum value of the parameter, as specified above
 *
 * return: The value of the parameter in the internal range for that parameter
 */
inline float TranslateParam_Norm2Inter(float val, float min, float max) {
    return val * (max - min) + min;
}

/* TranslateParam_Inter2Norm
 *
 * Translates parameter values from the range used internally for that
 * parameter, to the normalised range (0 to 1) as required by VSTs.
 *
 * args: val    Value of the parameter in the internal range
 *       min    The minimum value of the parameter, as specified above
 *       max    The maximum value of the parameter, as specified above
 *
 * return: The normalised value of the parameter
 */
inline float TranslateParam_Inter2Norm(float val, float min, float max) {
    return (val - min) / (max - min);
}

#endif  // PARAMETERDATA_H_INCLUDED
