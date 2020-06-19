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

    MOD1Group.reset (new GroupComponent ("MOD 1 Group",
                                         TRANS("LFO")));
    addAndMakeVisible (MOD1Group.get());
    MOD1Group->setTextLabelPosition (Justification::centred);
    MOD1Group->setColour (GroupComponent::outlineColourId, Colour (0xffff8773));
    MOD1Group->setColour (GroupComponent::textColourId, Colour (0xffff8773));

    MOD1Group->setBounds (72, 214, 280, 136);

    Vowel1Cmb.reset (new ComboBox ("Vowel 1 Combo Box"));
    addAndMakeVisible (Vowel1Cmb.get());
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

    Vowel1Cmb->setBounds (60, 64, 48, 24);

    FilterPosSld.reset (new Slider ("Filter Position Slider"));
    addAndMakeVisible (FilterPosSld.get());
    FilterPosSld->setTooltip (TRANS("Manully modulate between the two vowels using the mode selected below"));
    FilterPosSld->setRange (0, 1, 0);
    FilterPosSld->setSliderStyle (Slider::LinearHorizontal);
    FilterPosSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FilterPosSld->addListener (this);

    FilterPosSld->setBounds (124, 64, 184, 24);

    Vowel2Cmb.reset (new ComboBox ("Vowel 2 Combo Box"));
    addAndMakeVisible (Vowel2Cmb.get());
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

    Vowel2Cmb->setBounds (316, 64, 48, 24);

    MixSld.reset (new Slider ("Mix Slider"));
    addAndMakeVisible (MixSld.get());
    MixSld->setTooltip (TRANS("Dry/Wet mix level"));
    MixSld->setRange (0, 1, 0);
    MixSld->setSliderStyle (Slider::RotaryVerticalDrag);
    MixSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    MixSld->addListener (this);

    MixSld->setBounds (112, 117, 72, 56);

    DepthMOD1Sld.reset (new Slider ("MOD 1 Depth Slider"));
    addAndMakeVisible (DepthMOD1Sld.get());
    DepthMOD1Sld->setTooltip (TRANS("Depth of the LFO"));
    DepthMOD1Sld->setRange (0, 1, 0.01);
    DepthMOD1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    DepthMOD1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DepthMOD1Sld->addListener (this);

    DepthMOD1Sld->setBounds (151, 276, 32, 24);

    FreqMOD1Sld.reset (new Slider ("MOD 1 Freq Slider"));
    addAndMakeVisible (FreqMOD1Sld.get());
    FreqMOD1Sld->setTooltip (TRANS("Frequency of the LFO, from 2Hz to 20Hz"));
    FreqMOD1Sld->setRange (0, 1, 0.01);
    FreqMOD1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    FreqMOD1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FreqMOD1Sld->addListener (this);

    FreqMOD1Sld->setBounds (92, 276, 32, 24);

    WaveMOD1Cmb.reset (new ComboBox ("MOD 1 Wave"));
    addAndMakeVisible (WaveMOD1Cmb.get());
    WaveMOD1Cmb->setTooltip (TRANS("LFO wave shape"));
    WaveMOD1Cmb->setEditableText (false);
    WaveMOD1Cmb->setJustificationType (Justification::centredLeft);
    WaveMOD1Cmb->setTextWhenNothingSelected (String());
    WaveMOD1Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    WaveMOD1Cmb->addItem (TRANS("Sine"), 1);
    WaveMOD1Cmb->addItem (TRANS("Square"), 2);
    WaveMOD1Cmb->addItem (TRANS("Saw"), 3);
    WaveMOD1Cmb->addListener (this);

    WaveMOD1Cmb->setBounds (259, 283, 80, 24);

    FreqMOD1Lbl.reset (new Label ("MOD 1 Freq Label",
                                  TRANS("Rate")));
    addAndMakeVisible (FreqMOD1Lbl.get());
    FreqMOD1Lbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    FreqMOD1Lbl->setJustificationType (Justification::centredLeft);
    FreqMOD1Lbl->setEditable (false, false, false);
    FreqMOD1Lbl->setColour (Label::textColourId, Colour (0xffffdf5e));
    FreqMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    FreqMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    FreqMOD1Lbl->setBounds (86, 306, 56, 24);

    DepthMOD1Lbl.reset (new Label ("MOD 1 Depth Label",
                                   TRANS("Depth")));
    addAndMakeVisible (DepthMOD1Lbl.get());
    DepthMOD1Lbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    DepthMOD1Lbl->setJustificationType (Justification::centredLeft);
    DepthMOD1Lbl->setEditable (false, false, false);
    DepthMOD1Lbl->setColour (Label::textColourId, Colour (0xffffdf5e));
    DepthMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    DepthMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    DepthMOD1Lbl->setBounds (143, 306, 54, 24);

    TempoSyncMOD1Btn.reset (new TextButton ("MOD 1 Tempo Sync Button"));
    addAndMakeVisible (TempoSyncMOD1Btn.get());
    TempoSyncMOD1Btn->setTooltip (TRANS("Tempo sync LFO frequency"));
    TempoSyncMOD1Btn->setButtonText (TRANS("Tempo"));
    TempoSyncMOD1Btn->addListener (this);

    TempoSyncMOD1Btn->setBounds (83, 242, 54, 16);

    TempoNumerMOD1Sld.reset (new Slider ("MOD 1 Tempo Numer Slider"));
    addAndMakeVisible (TempoNumerMOD1Sld.get());
    TempoNumerMOD1Sld->setRange (1, 4, 1);
    TempoNumerMOD1Sld->setSliderStyle (Slider::IncDecButtons);
    TempoNumerMOD1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoNumerMOD1Sld->setColour (Slider::textBoxTextColourId, Colour (0xffffdf5e));
    TempoNumerMOD1Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0x00c8c8c8));
    TempoNumerMOD1Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoNumerMOD1Sld->addListener (this);

    TempoNumerMOD1Sld->setBounds (78, 274, 56, 16);

    TempoDenomMOD1Sld.reset (new Slider ("MOD 1 Tempo Denom Slider"));
    addAndMakeVisible (TempoDenomMOD1Sld.get());
    TempoDenomMOD1Sld->setRange (1, 32, 1);
    TempoDenomMOD1Sld->setSliderStyle (Slider::IncDecButtons);
    TempoDenomMOD1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    TempoDenomMOD1Sld->setColour (Slider::backgroundColourId, Colour (0xff263238));
    TempoDenomMOD1Sld->setColour (Slider::textBoxTextColourId, Colour (0xffffdf5e));
    TempoDenomMOD1Sld->setColour (Slider::textBoxBackgroundColourId, Colour (0x00c8c8c8));
    TempoDenomMOD1Sld->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    TempoDenomMOD1Sld->addListener (this);

    TempoDenomMOD1Sld->setBounds (78, 306, 56, 16);

    PhaseSyncMOD1Btn.reset (new TextButton ("MOD 1 Phase Sync Button"));
    addAndMakeVisible (PhaseSyncMOD1Btn.get());
    PhaseSyncMOD1Btn->setTooltip (TRANS("Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"));
    PhaseSyncMOD1Btn->setButtonText (TRANS("Sync"));
    PhaseSyncMOD1Btn->addListener (this);

    PhaseSyncMOD1Btn->setBounds (205, 242, 43, 16);

    PhaseMOD1Sld.reset (new Slider ("MOD 1 Phase Slider"));
    addAndMakeVisible (PhaseMOD1Sld.get());
    PhaseMOD1Sld->setTooltip (TRANS("Phase shift the LFO by up to 360 degrees"));
    PhaseMOD1Sld->setRange (0, 1, 0.01);
    PhaseMOD1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PhaseMOD1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PhaseMOD1Sld->addListener (this);

    PhaseMOD1Sld->setBounds (210, 276, 32, 24);

    PhaseMOD1Lbl.reset (new Label ("MOD 1 Phase Label",
                                   TRANS("Phase")));
    addAndMakeVisible (PhaseMOD1Lbl.get());
    PhaseMOD1Lbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    PhaseMOD1Lbl->setJustificationType (Justification::centredLeft);
    PhaseMOD1Lbl->setEditable (false, false, false);
    PhaseMOD1Lbl->setColour (Label::textColourId, Colour (0xffffdf5e));
    PhaseMOD1Lbl->setColour (TextEditor::textColourId, Colours::black);
    PhaseMOD1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PhaseMOD1Lbl->setBounds (202, 306, 56, 24);

    ModModeBtn.reset (new TextButton ("Mod Mode Button"));
    addAndMakeVisible (ModModeBtn.get());
    ModModeBtn->setTooltip (TRANS("Modulation mode: \"Blend\" applies both vowels in parallel and blends between the two, \"Freq\" applies a single vowel which is some combination of the two selected"));
    ModModeBtn->setButtonText (TRANS("Blend"));
    ModModeBtn->addListener (this);
    ModModeBtn->setColour (TextButton::buttonColourId, Colour (0xffffcc00));
    ModModeBtn->setColour (TextButton::buttonOnColourId, Colour (0xffff5032));
    ModModeBtn->setColour (TextButton::textColourOffId, Colour (0xffffcc00));
    ModModeBtn->setColour (TextButton::textColourOnId, Colour (0xffff5032));

    ModModeBtn->setBounds (248, 136, 64, 24);

    MixLbl.reset (new Label ("Mix Label",
                             TRANS("Mix")));
    addAndMakeVisible (MixLbl.get());
    MixLbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    MixLbl->setJustificationType (Justification::centredLeft);
    MixLbl->setEditable (false, false, false);
    MixLbl->setColour (Label::textColourId, Colour (0xffff8773));
    MixLbl->setColour (TextEditor::textColourId, Colours::black);
    MixLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    MixLbl->setBounds (132, 176, 32, 24);

    ModeLbl.reset (new Label ("Mode Label",
                              TRANS("Mode")));
    addAndMakeVisible (ModeLbl.get());
    ModeLbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    ModeLbl->setJustificationType (Justification::centredLeft);
    ModeLbl->setEditable (false, false, false);
    ModeLbl->setColour (Label::textColourId, Colour (0xffff8773));
    ModeLbl->setColour (TextEditor::textColourId, Colours::black);
    ModeLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    ModeLbl->setBounds (258, 176, 54, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (425, 350);


    //[Constructor] You can add your own custom stuff here..
    const Colour orangeHighlight(255, 80, 50);
    const Colour lightOrange(255, 118, 80);
    const Colour yellowHighlight(255, 204, 0);
    const Colour lightYellow(255, 221, 89);

    const Colour menuDark(0.0f, 0.0f, 0.17f, 1.0f);

    orangeLookAndFeel.setHighlightColours(orangeHighlight, yellowHighlight);
    yellowLookAndFeel.setHighlightColour(yellowHighlight);
    tempoButtonLookAndFeel.setHighlightColours(orangeHighlight, yellowHighlight);

    // Set the popup menu colours
    orangeLookAndFeel.setColour(PopupMenu::ColourIds::backgroundColourId,
                              menuDark);
    orangeLookAndFeel.setColour(PopupMenu::ColourIds::textColourId, lightOrange);
    orangeLookAndFeel.setColour(PopupMenu::ColourIds::highlightedBackgroundColourId,
                              lightOrange);
    orangeLookAndFeel.setColour(PopupMenu::ColourIds::highlightedTextColourId,
                                 menuDark);

    yellowLookAndFeel.setColour(PopupMenu::ColourIds::backgroundColourId,
                              menuDark);
    yellowLookAndFeel.setColour(PopupMenu::ColourIds::textColourId, lightYellow);
    yellowLookAndFeel.setColour(PopupMenu::ColourIds::highlightedBackgroundColourId,
                              lightYellow);
    yellowLookAndFeel.setColour(PopupMenu::ColourIds::highlightedTextColourId,
                              menuDark);

    tempoButtonLookAndFeel.setColour(TextButton::textColourOffId, yellowHighlight);


    // Assign the look and feel classes
    _assignLookAndFeelToAllChildren(orangeLookAndFeel);

    FreqMOD1Sld->setLookAndFeel(&yellowLookAndFeel);
    DepthMOD1Sld->setLookAndFeel(&yellowLookAndFeel);
    Vowel2Cmb->setLookAndFeel(&yellowLookAndFeel);
    PhaseMOD1Sld->setLookAndFeel(&yellowLookAndFeel);
    WaveMOD1Cmb->setLookAndFeel(&yellowLookAndFeel);

    TempoNumerMOD1Sld->setLookAndFeel(&tempoButtonLookAndFeel);
    TempoDenomMOD1Sld->setLookAndFeel(&tempoButtonLookAndFeel);

    startTimer(40);

    // make tempo sync buttons draggable
    TempoNumerMOD1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
    TempoDenomMOD1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);

    FreqMOD1Sld->setDoubleClickReturnValue(true,
        WECore::Richter::Parameters::FREQ.InteralToNormalised(WECore::Richter::Parameters::FREQ.defaultValue));
    DepthMOD1Sld->setDoubleClickReturnValue(true,
        WECore::Richter::Parameters::DEPTH.InteralToNormalised(WECore::Richter::Parameters::DEPTH.defaultValue));
    PhaseMOD1Sld->setDoubleClickReturnValue(true,
        WECore::Richter::Parameters::PHASE.InteralToNormalised(WECore::Richter::Parameters::PHASE.defaultValue));

    //[/Constructor]
}

SongbirdAudioProcessorEditor::~SongbirdAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    MOD1Group = nullptr;
    Vowel1Cmb = nullptr;
    FilterPosSld = nullptr;
    Vowel2Cmb = nullptr;
    MixSld = nullptr;
    DepthMOD1Sld = nullptr;
    FreqMOD1Sld = nullptr;
    WaveMOD1Cmb = nullptr;
    FreqMOD1Lbl = nullptr;
    DepthMOD1Lbl = nullptr;
    TempoSyncMOD1Btn = nullptr;
    TempoNumerMOD1Sld = nullptr;
    TempoDenomMOD1Sld = nullptr;
    PhaseSyncMOD1Btn = nullptr;
    PhaseMOD1Sld = nullptr;
    PhaseMOD1Lbl = nullptr;
    ModModeBtn = nullptr;
    MixLbl = nullptr;
    ModeLbl = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    _removeLookAndFeelFromAllChildren();
    //[/Destructor]
}

//==============================================================================
void SongbirdAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    Image bg = ImageCache::getFromMemory(BinaryData::Background_png, BinaryData::Background_pngSize);
    g.drawImage(bg, 0, 0, 425, 350, 0, 0, 5 * 425, 5 * 350);
    //[/UserPaint]
}

void SongbirdAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SongbirdAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    SongbirdAudioProcessor* ourProcessor {getProcessor()};
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == Vowel1Cmb.get())
    {
        //[UserComboBoxCode_Vowel1Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::vowel1,
                                   static_cast<float>(Vowel1Cmb->getSelectedId()));
        //[/UserComboBoxCode_Vowel1Cmb]
    }
    else if (comboBoxThatHasChanged == Vowel2Cmb.get())
    {
        //[UserComboBoxCode_Vowel2Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::vowel2,
                                   static_cast<float>(Vowel2Cmb->getSelectedId()));
        //[/UserComboBoxCode_Vowel2Cmb]
    }
    else if (comboBoxThatHasChanged == WaveMOD1Cmb.get())
    {
        //[UserComboBoxCode_WaveMOD1Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::waveMOD1,
                                   static_cast<float>(WaveMOD1Cmb->getSelectedId()));
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

    if (sliderThatWasMoved == FilterPosSld.get())
    {
        //[UserSliderCode_FilterPosSld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::filterPosition,
                                   static_cast<float>(FilterPosSld->getValue()));
        //[/UserSliderCode_FilterPosSld]
    }
    else if (sliderThatWasMoved == MixSld.get())
    {
        //[UserSliderCode_MixSld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::mix,
                                   static_cast<float>(MixSld->getValue()));
        //[/UserSliderCode_MixSld]
    }
    else if (sliderThatWasMoved == DepthMOD1Sld.get())
    {
        //[UserSliderCode_DepthMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::depthMOD1,
                                   static_cast<float>(DepthMOD1Sld->getValue()));
        //[/UserSliderCode_DepthMOD1Sld]
    }
    else if (sliderThatWasMoved == FreqMOD1Sld.get())
    {
        //[UserSliderCode_FreqMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::freqMOD1,
                                   static_cast<float>(FreqMOD1Sld->getValue()));
        //[/UserSliderCode_FreqMOD1Sld]
    }
    else if (sliderThatWasMoved == TempoNumerMOD1Sld.get())
    {
        //[UserSliderCode_TempoNumerMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::tempoNumerMOD1,
                                   static_cast<float>(TempoNumerMOD1Sld->getValue()));
        //[/UserSliderCode_TempoNumerMOD1Sld]
    }
    else if (sliderThatWasMoved == TempoDenomMOD1Sld.get())
    {
        //[UserSliderCode_TempoDenomMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::tempoDenomMOD1,
                                   static_cast<float>(TempoDenomMOD1Sld->getValue()));
        //[/UserSliderCode_TempoDenomMOD1Sld]
    }
    else if (sliderThatWasMoved == PhaseMOD1Sld.get())
    {
        //[UserSliderCode_PhaseMOD1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::phaseMOD1,
                                   static_cast<float>(PhaseMOD1Sld->getValue()));
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

    if (buttonThatWasClicked == TempoSyncMOD1Btn.get())
    {
        //[UserButtonCode_TempoSyncMOD1Btn] -- add your button handler code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::tempoSyncMOD1,
                                   static_cast<float>(TempoSyncMOD1Btn->getToggleState()));
        //[/UserButtonCode_TempoSyncMOD1Btn]
    }
    else if (buttonThatWasClicked == PhaseSyncMOD1Btn.get())
    {
        //[UserButtonCode_PhaseSyncMOD1Btn] -- add your button handler code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::phaseSyncMOD1,
                                   static_cast<float>(PhaseSyncMOD1Btn->getToggleState()));
        //[/UserButtonCode_PhaseSyncMOD1Btn]
    }
    else if (buttonThatWasClicked == ModModeBtn.get())
    {
        //[UserButtonCode_ModModeBtn] -- add your button handler code here..
        ourProcessor->setParameter(SongbirdAudioProcessor::modMode,
                                   static_cast<float>(ModModeBtn->getToggleState()));
        //[/UserButtonCode_ModModeBtn]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void SongbirdAudioProcessorEditor::timerCallback() {
    SongbirdAudioProcessor* ourProcessor {getProcessor()};

    if (ourProcessor->NeedsUIUpdate()) {
        Vowel1Cmb->setSelectedId(ourProcessor->getParameter(SongbirdAudioProcessor::vowel1),
                                                            dontSendNotification);
        Vowel2Cmb->setSelectedId(ourProcessor->getParameter(SongbirdAudioProcessor::vowel2),
                                                            dontSendNotification);
        FilterPosSld->setValue(ourProcessor->getParameter(SongbirdAudioProcessor::filterPosition),
                                                          dontSendNotification);
        MixSld->setValue(ourProcessor->getParameter(SongbirdAudioProcessor::mix),
                                                    dontSendNotification);
        ModModeBtn->setToggleState(ourProcessor->getParameter(SongbirdAudioProcessor::modMode),
                                                              dontSendNotification);

        // Set text for mod mode button
        ModModeBtn->getToggleState() ? ModModeBtn->setButtonText("FREQ") :
                                       ModModeBtn->setButtonText("BLEND");

        // MOD 1
        PhaseSyncMOD1Btn->setToggleState(
                ourProcessor->getParameter(SongbirdAudioProcessor::phaseSyncMOD1),
                                           dontSendNotification);
        TempoSyncMOD1Btn->setToggleState(
                ourProcessor->getParameter(SongbirdAudioProcessor::tempoSyncMOD1),
                                           dontSendNotification);
        WaveMOD1Cmb->setSelectedId(
                ourProcessor->getParameter(SongbirdAudioProcessor::waveMOD1),
                                           dontSendNotification);
        DepthMOD1Sld->setValue(
                ourProcessor->getParameter(SongbirdAudioProcessor::depthMOD1),
                                           dontSendNotification);
        FreqMOD1Sld->setValue(
                ourProcessor->getParameter(SongbirdAudioProcessor::freqMOD1),
                                           dontSendNotification);
        PhaseMOD1Sld->setValue(
                ourProcessor->getParameter(SongbirdAudioProcessor::phaseMOD1),
                                           dontSendNotification);
        TempoNumerMOD1Sld->setValue(
                ourProcessor->getParameter(SongbirdAudioProcessor::tempoNumerMOD1),
                                           dontSendNotification);
        TempoDenomMOD1Sld->setValue(
                ourProcessor->getParameter(SongbirdAudioProcessor::tempoDenomMOD1),
                                           dontSendNotification);

        // Activate/Deactivale phase control depending on phase sync
        PhaseMOD1Sld->setEnabled(PhaseSyncMOD1Btn->getToggleState());

        // Toggle visibility for rate controls depending on tempo sync
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

    // Pickup LFO output value
    orangeLookAndFeel.updateLFOOutput(ourProcessor->getLastLFOOutput());
    FilterPosSld->repaint();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SongbirdAudioProcessorEditor"
                 componentName="" parentClasses="public WECore::JUCEPlugin::CoreProcessorEditor, public Timer"
                 constructorParams="SongbirdAudioProcessor&amp; ownerFilter" variableInitialisers="CoreProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.33"
                 fixedSize="0" initialWidth="425" initialHeight="350">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GROUPCOMPONENT name="MOD 1 Group" id="a2c7412d0fb46a58" memberName="MOD1Group"
                  virtualName="" explicitFocusOrder="0" pos="72 214 280 136" outlinecol="ffff8773"
                  textcol="ffff8773" title="LFO" textpos="36"/>
  <COMBOBOX name="Vowel 1 Combo Box" id="ab5acbd6ca836993" memberName="Vowel1Cmb"
            virtualName="" explicitFocusOrder="0" pos="60 64 48 24" tooltip="Vowel to apply in the left position"
            editable="0" layout="33" items="A&#10;E&#10;I&#10;O&#10;U" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="Filter Position Slider" id="1be87d051f6ceb97" memberName="FilterPosSld"
          virtualName="Slider" explicitFocusOrder="0" pos="124 64 184 24"
          tooltip="Manully modulate between the two vowels using the mode selected below"
          min="0.0" max="1.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <COMBOBOX name="Vowel 2 Combo Box" id="9ac26013f2f51695" memberName="Vowel2Cmb"
            virtualName="" explicitFocusOrder="0" pos="316 64 48 24" tooltip="Vowel to apply in the right position"
            editable="0" layout="33" items="A&#10;E&#10;I&#10;O&#10;U" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="Mix Slider" id="b75c053482d8ac35" memberName="MixSld" virtualName=""
          explicitFocusOrder="0" pos="112 117 72 56" tooltip="Dry/Wet mix level"
          min="0.0" max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="MOD 1 Depth Slider" id="499f6451911662cc" memberName="DepthMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="151 276 32 24" tooltip="Depth of the LFO"
          min="0.0" max="1.0" int="0.01000000000000000021" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="MOD 1 Freq Slider" id="1d9800ca18cf5bba" memberName="FreqMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="92 276 32 24" tooltip="Frequency of the LFO, from 2Hz to 20Hz"
          min="0.0" max="1.0" int="0.01000000000000000021" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <COMBOBOX name="MOD 1 Wave" id="370e5062e67cf738" memberName="WaveMOD1Cmb"
            virtualName="" explicitFocusOrder="0" pos="259 283 80 24" tooltip="LFO wave shape"
            editable="0" layout="33" items="Sine&#10;Square&#10;Saw" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="MOD 1 Freq Label" id="dabfca26c640fd58" memberName="FreqMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="86 306 56 24" textCol="ffffdf5e"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="MOD 1 Depth Label" id="77092a4a55225c68" memberName="DepthMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="143 306 54 24" textCol="ffffdf5e"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="MOD 1 Tempo Sync Button" id="b43affdb8ac7bb90" memberName="TempoSyncMOD1Btn"
              virtualName="" explicitFocusOrder="0" pos="83 242 54 16" tooltip="Tempo sync LFO frequency"
              buttonText="Tempo" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="MOD 1 Tempo Numer Slider" id="6c49dac77f3e6f4b" memberName="TempoNumerMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="78 274 56 16" textboxtext="ffffdf5e"
          textboxbkgd="c8c8c8" textboxoutline="808080" min="1.0" max="4.0"
          int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="MOD 1 Tempo Denom Slider" id="a116d9c60bf4c7b5" memberName="TempoDenomMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="78 306 56 16" bkgcol="ff263238"
          textboxtext="ffffdf5e" textboxbkgd="c8c8c8" textboxoutline="808080"
          min="1.0" max="32.0" int="1.0" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="MOD 1 Phase Sync Button" id="4509e154e4918174" memberName="PhaseSyncMOD1Btn"
              virtualName="" explicitFocusOrder="0" pos="205 242 43 16" tooltip="Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"
              buttonText="Sync" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="MOD 1 Phase Slider" id="3f1ef3d10c303bac" memberName="PhaseMOD1Sld"
          virtualName="" explicitFocusOrder="0" pos="210 276 32 24" tooltip="Phase shift the LFO by up to 360 degrees"
          min="0.0" max="1.0" int="0.01000000000000000021" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="MOD 1 Phase Label" id="af1abf98d305cb5c" memberName="PhaseMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="202 306 56 24" textCol="ffffdf5e"
         edTextCol="ff000000" edBkgCol="0" labelText="Phase" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="Mod Mode Button" id="82ccbd2e4873bcd5" memberName="ModModeBtn"
              virtualName="" explicitFocusOrder="0" pos="248 136 64 24" tooltip="Modulation mode: &quot;Blend&quot; applies both vowels in parallel and blends between the two, &quot;Freq&quot; applies a single vowel which is some combination of the two selected"
              bgColOff="ffffcc00" bgColOn="ffff5032" textCol="ffffcc00" textColOn="ffff5032"
              buttonText="Blend" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="Mix Label" id="49736b42e5833ce0" memberName="MixLbl" virtualName=""
         explicitFocusOrder="0" pos="132 176 32 24" textCol="ffff8773"
         edTextCol="ff000000" edBkgCol="0" labelText="Mix" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="Mode Label" id="8aeac08f9afe843a" memberName="ModeLbl"
         virtualName="" explicitFocusOrder="0" pos="258 176 54 24" textCol="ffff8773"
         edTextCol="ff000000" edBkgCol="0" labelText="Mode" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]