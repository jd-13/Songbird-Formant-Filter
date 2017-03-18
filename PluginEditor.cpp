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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SongbirdAudioProcessorEditor::SongbirdAudioProcessorEditor (SongbirdAudioProcessor& ownerFilter)
    : CoreProcessorEditor(ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (Vowel1Cmb = new ComboBox ("Vowel 1 Combo Box"));
    Vowel1Cmb->setTooltip (TRANS("Vowel to apply in the left position"));
    Vowel1Cmb->setEditableText (false);
    Vowel1Cmb->setJustificationType (Justification::centredLeft);
    Vowel1Cmb->setTextWhenNothingSelected (String());
    Vowel1Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    Vowel1Cmb->addItem (TRANS("A"), 1);
    Vowel1Cmb->addItem (TRANS("E"), 2);
    Vowel1Cmb->addItem (TRANS("I"), 3);
    Vowel1Cmb->addItem (TRANS("O"), 4);
    Vowel1Cmb->addItem (TRANS("U"), 5);
    Vowel1Cmb->addListener (this);

    addAndMakeVisible (FilterPosSld = new Slider ("Filter Position Slider"));
    FilterPosSld->setTooltip (TRANS("Manully modulate between the two vowels using the mode selected below"));
    FilterPosSld->setRange (0, 1, 0);
    FilterPosSld->setSliderStyle (Slider::LinearHorizontal);
    FilterPosSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FilterPosSld->addListener (this);

    addAndMakeVisible (Vowel2Cmb = new ComboBox ("Vowel 2 Combo Box"));
    Vowel2Cmb->setTooltip (TRANS("Vowel to apply in the right position"));
    Vowel2Cmb->setEditableText (false);
    Vowel2Cmb->setJustificationType (Justification::centredLeft);
    Vowel2Cmb->setTextWhenNothingSelected (String());
    Vowel2Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    Vowel2Cmb->addItem (TRANS("A"), 1);
    Vowel2Cmb->addItem (TRANS("E"), 2);
    Vowel2Cmb->addItem (TRANS("I"), 3);
    Vowel2Cmb->addItem (TRANS("O"), 4);
    Vowel2Cmb->addItem (TRANS("U"), 5);
    Vowel2Cmb->addListener (this);

    addAndMakeVisible (MixSld = new Slider ("Mix Slider"));
    MixSld->setTooltip (TRANS("Dry/Wet mix level"));
    MixSld->setRange (0, 1, 0);
    MixSld->setSliderStyle (Slider::RotaryVerticalDrag);
    MixSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    MixSld->addListener (this);

    addAndMakeVisible (MOD1Group = new GroupComponent ("MOD 1 Group",
                                                       String()));
    MOD1Group->setColour (GroupComponent::outlineColourId, Colour (0x33545454));
    MOD1Group->setColour (GroupComponent::textColourId, Colours::black);

    addAndMakeVisible (DepthMOD1Sld = new Slider ("MOD 1 Depth Slider"));
    DepthMOD1Sld->setTooltip (TRANS("Depth of the LFO"));
    DepthMOD1Sld->setRange (0, 1, 0.01);
    DepthMOD1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthMOD1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthMOD1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff0d));
    DepthMOD1Sld->addListener (this);

    addAndMakeVisible (FreqMOD1Sld = new Slider ("MOD 1 Freq Slider"));
    FreqMOD1Sld->setTooltip (TRANS("Frequency of the LFO, from 2Hz to 20Hz"));
    FreqMOD1Sld->setRange (0, 1, 0.01);
    FreqMOD1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqMOD1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqMOD1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    FreqMOD1Sld->addListener (this);

    addAndMakeVisible (WaveMOD1Cmb = new ComboBox ("MOD 1 Wave"));
    WaveMOD1Cmb->setTooltip (TRANS("LFO wave shape"));
    WaveMOD1Cmb->setEditableText (false);
    WaveMOD1Cmb->setJustificationType (Justification::centredLeft);
    WaveMOD1Cmb->setTextWhenNothingSelected (String());
    WaveMOD1Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    WaveMOD1Cmb->addItem (TRANS("Sine"), 1);
    WaveMOD1Cmb->addItem (TRANS("Square"), 2);
    WaveMOD1Cmb->addItem (TRANS("Saw"), 3);
    WaveMOD1Cmb->addListener (this);

    addAndMakeVisible (BypassMOD1Btn = new TextButton ("MOD 1 Bypass Button"));
    BypassMOD1Btn->setTooltip (TRANS("Bypass button for the LFO. This LFO is basically moving the above modulation slider"));
    BypassMOD1Btn->setButtonText (TRANS("OSC"));
    BypassMOD1Btn->addListener (this);

    addAndMakeVisible (FreqMOD1Lbl = new Label ("MOD 1 Freq Label",
                                                TRANS("Rate")));
    FreqMOD1Lbl->setFont (Font (15.00f, Font::plain));
    FreqMOD1Lbl->setJustificationType (Justification::centredLeft);
    FreqMOD1Lbl->setEditable (false, false, false);
    FreqMOD1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    FreqMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    FreqMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DepthMOD1Lbl = new Label ("MOD 1 Depth Label",
                                                 TRANS("Depth")));
    DepthMOD1Lbl->setFont (Font (15.00f, Font::plain));
    DepthMOD1Lbl->setJustificationType (Justification::centredLeft);
    DepthMOD1Lbl->setEditable (false, false, false);
    DepthMOD1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    DepthMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    DepthMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (WaveMOD1Lbl = new Label ("MOD 1 Wave Label",
                                                TRANS("Wave\n")));
    WaveMOD1Lbl->setFont (Font (15.00f, Font::plain));
    WaveMOD1Lbl->setJustificationType (Justification::centredLeft);
    WaveMOD1Lbl->setEditable (false, false, false);
    WaveMOD1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    WaveMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    WaveMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (TempoSyncMOD1Btn = new TextButton ("MOD 1 Tempo Sync Button"));
    TempoSyncMOD1Btn->setTooltip (TRANS("Tempo sync LFO frequency"));
    TempoSyncMOD1Btn->setButtonText (TRANS("Tempo Sync"));
    TempoSyncMOD1Btn->addListener (this);

    addAndMakeVisible (TempoNumerMOD1Sld = new Slider ("MOD 1 Tempo Numer Slider"));
    TempoNumerMOD1Sld->setRange (1, 4, 1);
    TempoNumerMOD1Sld->setSliderStyle (Slider::IncDecButtons);
    TempoNumerMOD1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoNumerMOD1Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoNumerMOD1Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoNumerMOD1Sld->addListener (this);

    addAndMakeVisible (TempoDenomMOD1Sld = new Slider ("MOD 1 Tempo Denom Slider"));
    TempoDenomMOD1Sld->setRange (1, 32, 1);
    TempoDenomMOD1Sld->setSliderStyle (Slider::IncDecButtons);
    TempoDenomMOD1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoDenomMOD1Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0xffc8c8c8));
    TempoDenomMOD1Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoDenomMOD1Sld->addListener (this);

    addAndMakeVisible (PhaseSyncMOD1Btn = new TextButton ("MOD 1 Phase Sync Button"));
    PhaseSyncMOD1Btn->setTooltip (TRANS("Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"));
    PhaseSyncMOD1Btn->setButtonText (TRANS("Phase Sync"));
    PhaseSyncMOD1Btn->addListener (this);

    addAndMakeVisible (PhaseMOD1Sld = new Slider ("MOD 1 Phase Slider"));
    PhaseMOD1Sld->setTooltip (TRANS("Phase shift the LFO by up to 360 degrees"));
    PhaseMOD1Sld->setRange (0, 1, 0.01);
    PhaseMOD1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PhaseMOD1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PhaseMOD1Sld->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00ff03));
    PhaseMOD1Sld->addListener (this);

    addAndMakeVisible (PhaseMOD1Lbl = new Label ("MOD 1 Phase Label",
                                                 TRANS("Phase")));
    PhaseMOD1Lbl->setFont (Font (15.00f, Font::plain));
    PhaseMOD1Lbl->setJustificationType (Justification::centredLeft);
    PhaseMOD1Lbl->setEditable (false, false, false);
    PhaseMOD1Lbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    PhaseMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    PhaseMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ModModeBtn = new TextButton ("Mod Mode Button"));
    ModModeBtn->setTooltip (TRANS("Modulation mode: \"Blend\" applies both vowels in parallel and blends between the two, \"Freq\" applies a single vowel which is some combination of the two selected"));
    ModModeBtn->setButtonText (TRANS("Blend"));
    ModModeBtn->addListener (this);

    addAndMakeVisible (MixLbl = new Label ("Mix Label",
                                           TRANS("Mix")));
    MixLbl->setFont (Font (15.00f, Font::plain));
    MixLbl->setJustificationType (Justification::centredLeft);
    MixLbl->setEditable (false, false, false);
    MixLbl->setColour (Label::textColourId, Colour (0xffc8c8c8));
    MixLbl->setColour (TextEditor::textColourId, Colours::black);
    MixLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (425, 350);


    //[Constructor] You can add your own custom stuff here..
    _assignLookAndFeelToAllChildren(blueLookAndFeel);
    Colour blueHighlight(81, 65, 255);
    Colour redHighlight(222, 35, 35);
    blueLookAndFeel.setHighlightColours(blueHighlight, redHighlight);
    redLookAndFeel.setHighlightColour(redHighlight);
    toggleButtonLookAndFeel.setHighlightColours(blueHighlight, redHighlight);
    tempoButtonLookAndFeel.setHighlightColours(blueHighlight, redHighlight);


    Vowel2Cmb->setLookAndFeel(&redLookAndFeel);
    BypassMOD1Btn->setLookAndFeel(&redLookAndFeel);
    WaveMOD1Cmb->setLookAndFeel(&redLookAndFeel);
    ModModeBtn->setLookAndFeel(&toggleButtonLookAndFeel);
    TempoNumerMOD1Sld->setLookAndFeel(&tempoButtonLookAndFeel);
    TempoDenomMOD1Sld->setLookAndFeel(&tempoButtonLookAndFeel);

    startTimer(200);

    // make tempo sync buttons draggable
    TempoNumerMOD1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
    TempoDenomMOD1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);

    FreqMOD1Sld->setDoubleClickReturnValue(true, FREQ.InteralToNormalised(FREQ.defaultValue));
    DepthMOD1Sld->setDoubleClickReturnValue(true, DEPTH.InteralToNormalised(DEPTH.defaultValue));
    PhaseMOD1Sld->setDoubleClickReturnValue(true, PHASE.InteralToNormalised(PHASE.defaultValue));

    //[/Constructor]
}

SongbirdAudioProcessorEditor::~SongbirdAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    Vowel1Cmb = nullptr;
    FilterPosSld = nullptr;
    Vowel2Cmb = nullptr;
    MixSld = nullptr;
    MOD1Group = nullptr;
    DepthMOD1Sld = nullptr;
    FreqMOD1Sld = nullptr;
    WaveMOD1Cmb = nullptr;
    BypassMOD1Btn = nullptr;
    FreqMOD1Lbl = nullptr;
    DepthMOD1Lbl = nullptr;
    WaveMOD1Lbl = nullptr;
    TempoSyncMOD1Btn = nullptr;
    TempoNumerMOD1Sld = nullptr;
    TempoDenomMOD1Sld = nullptr;
    PhaseSyncMOD1Btn = nullptr;
    PhaseMOD1Sld = nullptr;
    PhaseMOD1Lbl = nullptr;
    ModModeBtn = nullptr;
    MixLbl = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SongbirdAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    Image bg = ImageCache::getFromMemory(BinaryData::Background_jpeg, BinaryData::Background_jpegSize);
    g.drawImage(bg, 0, 0, 425, 350, 0, 0, 5 * 425, 5 * 350);
    //[/UserPaint]
}

void SongbirdAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    Vowel1Cmb->setBounds (60, 56, 48, 24);
    FilterPosSld->setBounds (124, 56, 184, 24);
    Vowel2Cmb->setBounds (316, 56, 48, 24);
    MixSld->setBounds (136, 109, 72, 56);
    MOD1Group->setBounds (73, 200, 280, 128);
    DepthMOD1Sld->setBounds (153, 248, 32, 24);
    FreqMOD1Sld->setBounds (97, 248, 32, 24);
    WaveMOD1Cmb->setBounds (257, 256, 80, 24);
    BypassMOD1Btn->setBounds (281, 216, 56, 24);
    FreqMOD1Lbl->setBounds (95, 272, 40, 24);
    DepthMOD1Lbl->setBounds (147, 272, 46, 24);
    WaveMOD1Lbl->setBounds (273, 288, 46, 24);
    TempoSyncMOD1Btn->setBounds (89, 224, 56, 16);
    TempoNumerMOD1Sld->setBounds (89, 256, 56, 16);
    TempoDenomMOD1Sld->setBounds (89, 288, 56, 16);
    PhaseSyncMOD1Btn->setBounds (201, 224, 56, 16);
    PhaseMOD1Sld->setBounds (209, 248, 32, 24);
    PhaseMOD1Lbl->setBounds (201, 272, 46, 24);
    ModModeBtn->setBounds (228, 128, 64, 24);
    MixLbl->setBounds (156, 168, 32, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SongbirdAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    SongbirdAudioProcessor* ourProcessor {getProcessor()};
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == Vowel1Cmb)
    {
        //[UserComboBoxCode_Vowel1Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::vowel1, static_cast<float>(Vowel1Cmb->getSelectedId()));
        //[/UserComboBoxCode_Vowel1Cmb]
    }
    else if (comboBoxThatHasChanged == Vowel2Cmb)
    {
        //[UserComboBoxCode_Vowel2Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::vowel2, static_cast<float>(Vowel2Cmb->getSelectedId()));
        //[/UserComboBoxCode_Vowel2Cmb]
    }
    else if (comboBoxThatHasChanged == WaveMOD1Cmb)
    {
        //[UserComboBoxCode_WaveMOD1Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::waveMOD1, static_cast<float>(WaveMOD1Cmb->getSelectedId()));
        //[/UserComboBoxCode_WaveMOD1Cmb]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void SongbirdAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    SongbirdAudioProcessor* ourProcessor {getProcessor()};
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == FilterPosSld)
    {
        //[UserSliderCode_FilterPosSld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::filterPosition, static_cast<float>(FilterPosSld->getValue()));
        //[/UserSliderCode_FilterPosSld]
    }
    else if (sliderThatWasMoved == MixSld)
    {
        //[UserSliderCode_MixSld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::mix, static_cast<float>(MixSld->getValue()));
        //[/UserSliderCode_MixSld]
    }
    else if (sliderThatWasMoved == DepthMOD1Sld)
    {
        //[UserSliderCode_DepthMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::depthMOD1, static_cast<float>(DepthMOD1Sld->getValue()));
        //[/UserSliderCode_DepthMOD1Sld]
    }
    else if (sliderThatWasMoved == FreqMOD1Sld)
    {
        //[UserSliderCode_FreqMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::freqMOD1, static_cast<float>(FreqMOD1Sld->getValue()));
        //[/UserSliderCode_FreqMOD1Sld]
    }
    else if (sliderThatWasMoved == TempoNumerMOD1Sld)
    {
        //[UserSliderCode_TempoNumerMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::tempoNumerMOD1, static_cast<float>(TempoNumerMOD1Sld->getValue()));
        //[/UserSliderCode_TempoNumerMOD1Sld]
    }
    else if (sliderThatWasMoved == TempoDenomMOD1Sld)
    {
        //[UserSliderCode_TempoDenomMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::tempoDenomMOD1, static_cast<float>(TempoDenomMOD1Sld->getValue()));
        //[/UserSliderCode_TempoDenomMOD1Sld]
    }
    else if (sliderThatWasMoved == PhaseMOD1Sld)
    {
        //[UserSliderCode_PhaseMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::phaseMOD1, static_cast<float>(PhaseMOD1Sld->getValue()));
        //[/UserSliderCode_PhaseMOD1Sld]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void SongbirdAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    SongbirdAudioProcessor* ourProcessor {getProcessor()};
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == BypassMOD1Btn)
    {
        //[UserButtonCode_BypassMOD1Btn] -- add your button handler code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::bypassSwitchMOD1, static_cast<float>(BypassMOD1Btn->getToggleState()));
        //[/UserButtonCode_BypassMOD1Btn]
    }
    else if (buttonThatWasClicked == TempoSyncMOD1Btn)
    {
        //[UserButtonCode_TempoSyncMOD1Btn] -- add your button handler code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::tempoSyncMOD1, static_cast<float>(TempoSyncMOD1Btn->getToggleState()));
        //[/UserButtonCode_TempoSyncMOD1Btn]
    }
    else if (buttonThatWasClicked == PhaseSyncMOD1Btn)
    {
        //[UserButtonCode_PhaseSyncMOD1Btn] -- add your button handler code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::phaseSyncMOD1, static_cast<float>(PhaseSyncMOD1Btn->getToggleState()));
        //[/UserButtonCode_PhaseSyncMOD1Btn]
    }
    else if (buttonThatWasClicked == ModModeBtn)
    {
        //[UserButtonCode_ModModeBtn] -- add your button handler code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::modMode, static_cast<float>(ModModeBtn->getToggleState()));
        //[/UserButtonCode_ModModeBtn]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void SongbirdAudioProcessorEditor::timerCallback() {
    SongbirdAudioProcessor* ourProcessor {getProcessor()};

    if (ourProcessor->NeedsUIUpdate()) {
        Vowel1Cmb->setSelectedId(ourProcessor->getParameter(SongbirdAudioProcessor::vowel1), dontSendNotification);
        Vowel2Cmb->setSelectedId(ourProcessor->getParameter(SongbirdAudioProcessor::vowel2), dontSendNotification);
        FilterPosSld->setValue(ourProcessor->getParameter(SongbirdAudioProcessor::filterPosition), dontSendNotification);
        MixSld->setValue(ourProcessor->getParameter(SongbirdAudioProcessor::mix), dontSendNotification);
        ModModeBtn->setToggleState(ourProcessor->getParameter(SongbirdAudioProcessor::modMode), dontSendNotification);

        // Set text for mod mode button
        ModModeBtn->getToggleState() ? ModModeBtn->setButtonText("FREQ") : ModModeBtn->setButtonText("BLEND");

        // MOD 1
        BypassMOD1Btn->setToggleState(ourProcessor->getParameter(SongbirdAudioProcessor::bypassSwitchMOD1), dontSendNotification);
        PhaseSyncMOD1Btn->setToggleState(ourProcessor->getParameter(SongbirdAudioProcessor::phaseSyncMOD1), dontSendNotification);
        TempoSyncMOD1Btn->setToggleState(ourProcessor->getParameter(SongbirdAudioProcessor::tempoSyncMOD1), dontSendNotification);
        WaveMOD1Cmb->setSelectedId(ourProcessor->getParameter(SongbirdAudioProcessor::waveMOD1), dontSendNotification);
        DepthMOD1Sld->setValue(ourProcessor->getParameter(SongbirdAudioProcessor::depthMOD1), dontSendNotification);
        FreqMOD1Sld->setValue(ourProcessor->getParameter(SongbirdAudioProcessor::freqMOD1), dontSendNotification);
        PhaseMOD1Sld->setValue(ourProcessor->getParameter(SongbirdAudioProcessor::phaseMOD1), dontSendNotification);
        TempoNumerMOD1Sld->setValue(ourProcessor->getParameter(SongbirdAudioProcessor::tempoNumerMOD1), dontSendNotification);
        TempoDenomMOD1Sld->setValue(ourProcessor->getParameter(SongbirdAudioProcessor::tempoDenomMOD1), dontSendNotification);

        // Activate/Deactivale phase control depending on phase sync
        PhaseMOD1Sld->setEnabled(PhaseSyncMOD1Btn->getToggleState());

        // Toggle visibility for rate controls and move MOD labels depending on tempo sync
        if (TempoSyncMOD1Btn->getToggleState()) {
            FreqMOD1Sld->setVisible(false);
            FreqMOD1Lbl->setVisible(false);
            TempoNumerMOD1Sld->setVisible(true);
            TempoDenomMOD1Sld->setVisible(true);
        } else {
            FreqMOD1Sld->setVisible(true);
            FreqMOD1Lbl->setVisible(true);
            TempoNumerMOD1Sld->setVisible(false);
            TempoDenomMOD1Sld->setVisible(false);
        }
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SongbirdAudioProcessorEditor"
                 componentName="" parentClasses="public CoreProcessorEditor, public Timer"
                 constructorParams="SongbirdAudioProcessor&amp; ownerFilter" variableInitialisers="CoreProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="425" initialHeight="350">
  <BACKGROUND backgroundColour="ffffffff"/>
  <COMBOBOX name="Vowel 1 Combo Box" id="ab5acbd6ca836993" memberName="Vowel1Cmb"
            virtualName="" explicitFocusOrder="0" pos="60 56 48 24" tooltip="Vowel to apply in the left position"
            editable="0" layout="33" items="A&#10;E&#10;I&#10;O&#10;U" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="Filter Position Slider" id="1be87d051f6ceb97" memberName="FilterPosSld"
          virtualName="" explicitFocusOrder="0" pos="124 56 184 24" tooltip="Manully modulate between the two vowels using the mode selected below"
          min="0" max="1" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <COMBOBOX name="Vowel 2 Combo Box" id="9ac26013f2f51695" memberName="Vowel2Cmb"
            virtualName="" explicitFocusOrder="0" pos="316 56 48 24" tooltip="Vowel to apply in the right position"
            editable="0" layout="33" items="A&#10;E&#10;I&#10;O&#10;U" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="Mix Slider" id="b75c053482d8ac35" memberName="MixSld" virtualName=""
          explicitFocusOrder="0" pos="136 109 72 56" tooltip="Dry/Wet mix level"
          min="0" max="1" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <GROUPCOMPONENT name="MOD 1 Group" id="a2c7412d0fb46a58" memberName="MOD1Group"
                  virtualName="" explicitFocusOrder="0" pos="73 200 280 128" outlinecol="33545454"
                  textcol="ff000000" title=""/>
  <SLIDER name="MOD 1 Depth Slider" id="499f6451911662cc" memberName="DepthMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="153 248 32 24" tooltip="Depth of the LFO"
          rotarysliderfill="7f00ff0d" min="0" max="1" int="0.010000000000000000208"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="MOD 1 Freq Slider" id="1d9800ca18cf5bba" memberName="FreqMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="97 248 32 24" tooltip="Frequency of the LFO, from 2Hz to 20Hz"
          rotarysliderfill="7f00ff03" min="0" max="1" int="0.010000000000000000208"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <COMBOBOX name="MOD 1 Wave" id="370e5062e67cf738" memberName="WaveMOD1Cmb"
            virtualName="" explicitFocusOrder="0" pos="257 256 80 24" tooltip="LFO wave shape"
            editable="0" layout="33" items="Sine&#10;Square&#10;Saw" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="MOD 1 Bypass Button" id="cd667ff923e74db5" memberName="BypassMOD1Btn"
              virtualName="" explicitFocusOrder="0" pos="281 216 56 24" tooltip="Bypass button for the LFO. This LFO is basically moving the above modulation slider"
              buttonText="OSC" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="MOD 1 Freq Label" id="dabfca26c640fd58" memberName="FreqMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="95 272 40 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="MOD 1 Depth Label" id="77092a4a55225c68" memberName="DepthMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="147 272 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="MOD 1 Wave Label" id="7eb50c1a44463588" memberName="WaveMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="273 288 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Wave&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="MOD 1 Tempo Sync Button" id="b43affdb8ac7bb90" memberName="TempoSyncMOD1Btn"
              virtualName="" explicitFocusOrder="0" pos="89 224 56 16" tooltip="Tempo sync LFO frequency"
              buttonText="Tempo Sync" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="MOD 1 Tempo Numer Slider" id="6c49dac77f3e6f4b" memberName="TempoNumerMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="89 256 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1" max="4" int="1" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="MOD 1 Tempo Denom Slider" id="a116d9c60bf4c7b5" memberName="TempoDenomMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="89 288 56 16" textboxbkgd="ffc8c8c8"
          textboxoutline="808080" min="1" max="32" int="1" style="IncDecButtons"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <TEXTBUTTON name="MOD 1 Phase Sync Button" id="4509e154e4918174" memberName="PhaseSyncMOD1Btn"
              virtualName="" explicitFocusOrder="0" pos="201 224 56 16" tooltip="Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"
              buttonText="Phase Sync" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="MOD 1 Phase Slider" id="3f1ef3d10c303bac" memberName="PhaseMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="209 248 32 24" tooltip="Phase shift the LFO by up to 360 degrees"
          rotarysliderfill="7f00ff03" min="0" max="1" int="0.010000000000000000208"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <LABEL name="MOD 1 Phase Label" id="af1abf98d305cb5c" memberName="PhaseMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="201 272 46 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Phase" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="Mod Mode Button" id="82ccbd2e4873bcd5" memberName="ModModeBtn"
              virtualName="" explicitFocusOrder="0" pos="228 128 64 24" tooltip="Modulation mode: &quot;Blend&quot; applies both vowels in parallel and blends between the two, &quot;Freq&quot; applies a single vowel which is some combination of the two selected"
              buttonText="Blend" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="Mix Label" id="49736b42e5833ce0" memberName="MixLbl" virtualName=""
         explicitFocusOrder="0" pos="156 168 32 24" textCol="ffc8c8c8"
         edTextCol="ff000000" edBkgCol="0" labelText="Mix" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
