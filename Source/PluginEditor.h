/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "SongbirdLookAndFeel.h"
#include "CoreJUCEPlugin/CoreProcessorEditor.h"
#include "CoreJUCEPlugin/LabelReadoutSlider.h"
#include "RichterLFO/UI/RichterWaveViewer.h"
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
                                      public juce::ComboBox::Listener,
                                      public juce::Slider::Listener,
                                      public juce::Button::Listener
{
public:
    //==============================================================================
    SongbirdAudioProcessorEditor (SongbirdAudioProcessor& ownerFilter);
    ~SongbirdAudioProcessorEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback() override;
    SongbirdAudioProcessor* getProcessor() const {
        return static_cast<SongbirdAudioProcessor*>(getAudioProcessor());
    }
    void sliderDragStarted(Slider* slider) override;
    void sliderDragEnded(Slider* slider) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SongbirdLookAndFeel orangeLookAndFeel,
                        yellowLookAndFeel;

    SongbirdTempoButtonLookAndFeel tempoButtonLookAndFeel;

    virtual void _onParameterUpdate() override;
    void _enableDoubleClickToDefault();
    void _startSliderReadouts();
    void _stopSliderReadouts();
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> MOD1Group;
    std::unique_ptr<juce::ComboBox> Vowel1Cmb;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FilterPosSld;
    std::unique_ptr<juce::ComboBox> Vowel2Cmb;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> MixSld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> DepthMOD1Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> FreqMOD1Sld;
    std::unique_ptr<juce::ComboBox> WaveMOD1Cmb;
    std::unique_ptr<juce::Label> FreqMOD1Lbl;
    std::unique_ptr<juce::Label> DepthMOD1Lbl;
    std::unique_ptr<juce::TextButton> TempoSyncMOD1Btn;
    std::unique_ptr<juce::Slider> TempoNumerMOD1Sld;
    std::unique_ptr<juce::Slider> TempoDenomMOD1Sld;
    std::unique_ptr<juce::TextButton> PhaseSyncMOD1Btn;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> PhaseMOD1Sld;
    std::unique_ptr<juce::Label> PhaseMOD1Lbl;
    std::unique_ptr<juce::TextButton> ModModeBtn;
    std::unique_ptr<juce::Label> MixLbl;
    std::unique_ptr<juce::Label> ModeLbl;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> OutputGainSld;
    std::unique_ptr<juce::Label> OutputGainLbl;
    std::unique_ptr<juce::Label> FilterPosLbl;
    std::unique_ptr<WECore::Richter::WaveViewer> WaveViewMOD1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SongbirdAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

