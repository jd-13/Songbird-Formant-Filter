/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_FB11CC1EF8D14C0F__
#define __JUCE_HEADER_FB11CC1EF8D14C0F__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "SongbirdLookAndFeel.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SongbirdAudioProcessorEditor  : public AudioProcessorEditor,
                                      public Timer,
                                      public ComboBoxListener,
                                      public SliderListener,
                                      public ButtonListener
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
    SongbirdLookAndFeel blueLookAndFeel,
                        redLookAndFeel;

    SongbirdButtonLookAndFeel toggleButtonLookAndFeel;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ComboBox> Vowel1Cmb;
    ScopedPointer<Slider> FilterPosSld;
    ScopedPointer<ComboBox> Vowel2Cmb;
    ScopedPointer<Slider> MixSld;
    ScopedPointer<GroupComponent> MOD1Group;
    ScopedPointer<Slider> DepthMOD1Sld;
    ScopedPointer<Slider> FreqMOD1Sld;
    ScopedPointer<ComboBox> WaveMOD1Cmb;
    ScopedPointer<TextButton> BypassMOD1Btn;
    ScopedPointer<Label> FreqMOD1Lbl;
    ScopedPointer<Label> DepthMOD1Lbl;
    ScopedPointer<Label> WaveMOD1Lbl;
    ScopedPointer<TextButton> TempoSyncMOD1Btn;
    ScopedPointer<Slider> TempoNumerMOD1Sld;
    ScopedPointer<Slider> TempoDenomMOD1Sld;
    ScopedPointer<TextButton> PhaseSyncMOD1Btn;
    ScopedPointer<Slider> PhaseMOD1Sld;
    ScopedPointer<Label> PhaseMOD1Lbl;
    ScopedPointer<TextButton> ModModeBtn;
    ScopedPointer<Label> MixLbl;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SongbirdAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_FB11CC1EF8D14C0F__
