/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "SongbirdLookAndFeel.h"
#include "CoreJUCEPlugin/CoreProcessorEditor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SongbirdAudioProcessorEditor  : public WECore::JUCEPlugin::CoreProcessorEditor,
                                      public Timer,
                                      public ComboBox::Listener,
                                      public Slider::Listener,
                                      public Button::Listener
{
public:
    //==============================================================================
    SongbirdAudioProcessorEditor (SongbirdAudioProcessor& ownerFilter);
    ~SongbirdAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback() override;
    SongbirdAudioProcessor* getProcessor() const {
        return static_cast<SongbirdAudioProcessor*>(getAudioProcessor());
    }
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SongbirdLookAndFeel orangeLookAndFeel,
                        yellowLookAndFeel;

    SongbirdTempoButtonLookAndFeel tempoButtonLookAndFeel;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<ComboBox> Vowel1Cmb;
    std::unique_ptr<Slider> FilterPosSld;
    std::unique_ptr<ComboBox> Vowel2Cmb;
    std::unique_ptr<Slider> MixSld;
    std::unique_ptr<GroupComponent> MOD1Group;
    std::unique_ptr<Slider> DepthMOD1Sld;
    std::unique_ptr<Slider> FreqMOD1Sld;
    std::unique_ptr<ComboBox> WaveMOD1Cmb;
    std::unique_ptr<TextButton> BypassMOD1Btn;
    std::unique_ptr<Label> FreqMOD1Lbl;
    std::unique_ptr<Label> DepthMOD1Lbl;
    std::unique_ptr<Label> WaveMOD1Lbl;
    std::unique_ptr<TextButton> TempoSyncMOD1Btn;
    std::unique_ptr<Slider> TempoNumerMOD1Sld;
    std::unique_ptr<Slider> TempoDenomMOD1Sld;
    std::unique_ptr<TextButton> PhaseSyncMOD1Btn;
    std::unique_ptr<Slider> PhaseMOD1Sld;
    std::unique_ptr<Label> PhaseMOD1Lbl;
    std::unique_ptr<TextButton> ModModeBtn;
    std::unique_ptr<Label> MixLbl;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SongbirdAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
