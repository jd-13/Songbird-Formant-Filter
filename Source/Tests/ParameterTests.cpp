/*
  ==============================================================================

    ParameterTests.cpp
    Created: 19 Mar 2017 4:50:41pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "catch.hpp"
#include "Tests/CoreTestLib.h"

SCENARIO("Parameters can be set and retrieved correctly") {
    GIVEN("A new SongbirdAudioProcessor object") {
        SongbirdAudioProcessor mProcessor;
        
        WHEN("Nothing is changed") {
            THEN("Parameters have their default values") {
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::vowel1) == 1);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::vowel2) == 1);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::filterPosition) == 0.5f);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::mix) == 1.0f);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::modMode) == false);
                
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::bypassSwitchMOD1) == 0);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::phaseSyncMOD1) == 0);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::tempoSyncMOD1) == 0);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::waveMOD1) == 1);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::depthMOD1) == 0.5f);
                REQUIRE(CoreTestLib::compareFloats(mProcessor.getParameter(SongbirdAudioProcessor::freqMOD1), 0.07692f, CoreTestLib::TOLERANCE_4DP));
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::phaseMOD1) == 0.0f);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::tempoNumerMOD1) == 1);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::tempoDenomMOD1) == 1);
            }
        }
        
        WHEN("All parameters (except bools) are changed to unique values") {
            mProcessor.setParameter(SongbirdAudioProcessor::vowel1, 2);
            mProcessor.setParameter(SongbirdAudioProcessor::vowel2, 3);
            mProcessor.setParameter(SongbirdAudioProcessor::filterPosition, 0.3f);
            mProcessor.setParameter(SongbirdAudioProcessor::mix, 0.4f);
            mProcessor.setParameter(SongbirdAudioProcessor::modMode, 0);
            
            mProcessor.setParameter(SongbirdAudioProcessor::bypassSwitchMOD1, 1);
            mProcessor.setParameter(SongbirdAudioProcessor::phaseSyncMOD1, 1);
            mProcessor.setParameter(SongbirdAudioProcessor::tempoSyncMOD1, 1);
            mProcessor.setParameter(SongbirdAudioProcessor::waveMOD1, 2);
            mProcessor.setParameter(SongbirdAudioProcessor::depthMOD1, 0.6f);
            mProcessor.setParameter(SongbirdAudioProcessor::freqMOD1, 0.7f);
            mProcessor.setParameter(SongbirdAudioProcessor::phaseMOD1, 0.8f);
            mProcessor.setParameter(SongbirdAudioProcessor::tempoNumerMOD1, 4);
            mProcessor.setParameter(SongbirdAudioProcessor::tempoDenomMOD1, 5);
            
            THEN("They all get their correct unique values") {
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::vowel1) == 2);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::vowel2) == 3);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::filterPosition) == 0.3f);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::mix) == 0.4f);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::modMode) == true);
                
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::bypassSwitchMOD1) == 0);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::phaseSyncMOD1) == 0);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::tempoSyncMOD1) == 0);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::waveMOD1) == 2);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::depthMOD1) == 0.6f);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::freqMOD1) == 0.7f);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::phaseMOD1) == 0.8f);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::tempoNumerMOD1) == 4);
                REQUIRE(mProcessor.getParameter(SongbirdAudioProcessor::tempoDenomMOD1) == 5);
            }
        }
    }
}