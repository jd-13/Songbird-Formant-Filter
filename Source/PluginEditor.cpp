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

    MOD1Group.reset (new juce::GroupComponent ("MOD 1 Group",
                                               TRANS("LFO")));
    addAndMakeVisible (MOD1Group.get());
    MOD1Group->setTextLabelPosition (juce::Justification::centred);
    MOD1Group->setColour (juce::GroupComponent::outlineColourId, juce::Colour (0xffffdf5e));
    MOD1Group->setColour (juce::GroupComponent::textColourId, juce::Colour (0xffffdf5e));

    MOD1Group->setBounds (72, 214, 280, 136);

    Vowel1Cmb.reset (new juce::ComboBox ("Vowel 1 Combo Box"));
    addAndMakeVisible (Vowel1Cmb.get());
    Vowel1Cmb->setTooltip (TRANS("Vowel to apply in the left position"));
    Vowel1Cmb->setEditableText (false);
    Vowel1Cmb->setJustificationType (juce::Justification::centredLeft);
    Vowel1Cmb->setTextWhenNothingSelected (juce::String());
    Vowel1Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    Vowel1Cmb->addItem (TRANS("A"), 1);
    Vowel1Cmb->addItem (TRANS("E"), 2);
    Vowel1Cmb->addItem (TRANS("I"), 3);
    Vowel1Cmb->addItem (TRANS("O"), 4);
    Vowel1Cmb->addItem (TRANS("U"), 5);
    Vowel1Cmb->addListener (this);

    Vowel1Cmb->setBounds (60, 64, 48, 24);

    FilterPosSld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("Filter Position Slider"));
    addAndMakeVisible (FilterPosSld.get());
    FilterPosSld->setTooltip (TRANS("Manully modulate between the two vowels using the mode selected below"));
    FilterPosSld->setRange (0, 1, 0.01);
    FilterPosSld->setSliderStyle (juce::Slider::LinearHorizontal);
    FilterPosSld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    FilterPosSld->addListener (this);

    FilterPosSld->setBounds (124, 64, 184, 24);

    Vowel2Cmb.reset (new juce::ComboBox ("Vowel 2 Combo Box"));
    addAndMakeVisible (Vowel2Cmb.get());
    Vowel2Cmb->setTooltip (TRANS("Vowel to apply in the right position"));
    Vowel2Cmb->setEditableText (false);
    Vowel2Cmb->setJustificationType (juce::Justification::centredLeft);
    Vowel2Cmb->setTextWhenNothingSelected (juce::String());
    Vowel2Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    Vowel2Cmb->addItem (TRANS("A"), 1);
    Vowel2Cmb->addItem (TRANS("E"), 2);
    Vowel2Cmb->addItem (TRANS("I"), 3);
    Vowel2Cmb->addItem (TRANS("O"), 4);
    Vowel2Cmb->addItem (TRANS("U"), 5);
    Vowel2Cmb->addListener (this);

    Vowel2Cmb->setBounds (316, 64, 48, 24);

    MixSld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("Mix Slider"));
    addAndMakeVisible (MixSld.get());
    MixSld->setTooltip (TRANS("Dry/Wet mix level"));
    MixSld->setRange (0, 1, 0.01);
    MixSld->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    MixSld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    MixSld->addListener (this);

    MixSld->setBounds (75, 117, 72, 56);

    DepthMOD1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("MOD 1 Depth Slider"));
    addAndMakeVisible (DepthMOD1Sld.get());
    DepthMOD1Sld->setTooltip (TRANS("Depth of the LFO"));
    DepthMOD1Sld->setRange (0, 1, 0.01);
    DepthMOD1Sld->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    DepthMOD1Sld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    DepthMOD1Sld->addListener (this);

    DepthMOD1Sld->setBounds (151, 276, 32, 24);

    FreqMOD1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("MOD 1 Freq Slider"));
    addAndMakeVisible (FreqMOD1Sld.get());
    FreqMOD1Sld->setTooltip (TRANS("Frequency of the LFO, from 2Hz to 20Hz"));
    FreqMOD1Sld->setRange (0, 1, 0.01);
    FreqMOD1Sld->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    FreqMOD1Sld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    FreqMOD1Sld->addListener (this);

    FreqMOD1Sld->setBounds (92, 276, 32, 24);

    WaveMOD1Cmb.reset (new juce::ComboBox ("MOD 1 Wave"));
    addAndMakeVisible (WaveMOD1Cmb.get());
    WaveMOD1Cmb->setTooltip (TRANS("LFO wave shape"));
    WaveMOD1Cmb->setEditableText (false);
    WaveMOD1Cmb->setJustificationType (juce::Justification::centredLeft);
    WaveMOD1Cmb->setTextWhenNothingSelected (juce::String());
    WaveMOD1Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    WaveMOD1Cmb->addItem (TRANS("Sine"), 1);
    WaveMOD1Cmb->addItem (TRANS("Square"), 2);
    WaveMOD1Cmb->addItem (TRANS("Saw"), 3);
    WaveMOD1Cmb->addItem (TRANS("SC Comp"), 4);
    WaveMOD1Cmb->addListener (this);

    WaveMOD1Cmb->setBounds (259, 306, 80, 24);

    FreqMOD1Lbl.reset (new juce::Label ("MOD 1 Freq Label",
                                        TRANS("Rate")));
    addAndMakeVisible (FreqMOD1Lbl.get());
    FreqMOD1Lbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    FreqMOD1Lbl->setJustificationType (juce::Justification::centred);
    FreqMOD1Lbl->setEditable (false, false, false);
    FreqMOD1Lbl->setColour (juce::Label::textColourId, juce::Colour (0xffffdf5e));
    FreqMOD1Lbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    FreqMOD1Lbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    FreqMOD1Lbl->setBounds (80, 306, 56, 24);

    DepthMOD1Lbl.reset (new juce::Label ("MOD 1 Depth Label",
                                         TRANS("Depth")));
    addAndMakeVisible (DepthMOD1Lbl.get());
    DepthMOD1Lbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    DepthMOD1Lbl->setJustificationType (juce::Justification::centred);
    DepthMOD1Lbl->setEditable (false, false, false);
    DepthMOD1Lbl->setColour (juce::Label::textColourId, juce::Colour (0xffffdf5e));
    DepthMOD1Lbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    DepthMOD1Lbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    DepthMOD1Lbl->setBounds (139, 306, 54, 24);

    TempoSyncMOD1Btn.reset (new juce::TextButton ("MOD 1 Tempo Sync Button"));
    addAndMakeVisible (TempoSyncMOD1Btn.get());
    TempoSyncMOD1Btn->setTooltip (TRANS("Tempo sync LFO frequency"));
    TempoSyncMOD1Btn->setButtonText (TRANS("Tempo"));
    TempoSyncMOD1Btn->addListener (this);

    TempoSyncMOD1Btn->setBounds (83, 242, 54, 16);

    TempoNumerMOD1Sld.reset (new juce::Slider ("MOD 1 Tempo Numer Slider"));
    addAndMakeVisible (TempoNumerMOD1Sld.get());
    TempoNumerMOD1Sld->setRange (1, 4, 1);
    TempoNumerMOD1Sld->setSliderStyle (juce::Slider::IncDecButtons);
    TempoNumerMOD1Sld->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    TempoNumerMOD1Sld->setColour (juce::Slider::textBoxTextColourId, juce::Colour (0xffffdf5e));
    TempoNumerMOD1Sld->setColour (juce::Slider::textBoxBackgroundColourId, juce::Colour (0x00c8c8c8));
    TempoNumerMOD1Sld->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00808080));
    TempoNumerMOD1Sld->addListener (this);

    TempoNumerMOD1Sld->setBounds (78, 274, 56, 16);

    TempoDenomMOD1Sld.reset (new juce::Slider ("MOD 1 Tempo Denom Slider"));
    addAndMakeVisible (TempoDenomMOD1Sld.get());
    TempoDenomMOD1Sld->setRange (1, 32, 1);
    TempoDenomMOD1Sld->setSliderStyle (juce::Slider::IncDecButtons);
    TempoDenomMOD1Sld->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 20);
    TempoDenomMOD1Sld->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff263238));
    TempoDenomMOD1Sld->setColour (juce::Slider::textBoxTextColourId, juce::Colour (0xffffdf5e));
    TempoDenomMOD1Sld->setColour (juce::Slider::textBoxBackgroundColourId, juce::Colour (0x00c8c8c8));
    TempoDenomMOD1Sld->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x00808080));
    TempoDenomMOD1Sld->addListener (this);

    TempoDenomMOD1Sld->setBounds (78, 306, 56, 16);

    PhaseSyncMOD1Btn.reset (new juce::TextButton ("MOD 1 Phase Sync Button"));
    addAndMakeVisible (PhaseSyncMOD1Btn.get());
    PhaseSyncMOD1Btn->setTooltip (TRANS("Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"));
    PhaseSyncMOD1Btn->setButtonText (TRANS("Phase"));
    PhaseSyncMOD1Btn->addListener (this);

    PhaseSyncMOD1Btn->setBounds (199, 242, 54, 16);

    PhaseMOD1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("MOD 1 Phase Slider"));
    addAndMakeVisible (PhaseMOD1Sld.get());
    PhaseMOD1Sld->setTooltip (TRANS("Phase shift the LFO by up to 360 degrees"));
    PhaseMOD1Sld->setRange (0, 1, 0.01);
    PhaseMOD1Sld->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    PhaseMOD1Sld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    PhaseMOD1Sld->addListener (this);

    PhaseMOD1Sld->setBounds (210, 276, 32, 24);

    PhaseMOD1Lbl.reset (new juce::Label ("MOD 1 Phase Label",
                                         TRANS("Phase")));
    addAndMakeVisible (PhaseMOD1Lbl.get());
    PhaseMOD1Lbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    PhaseMOD1Lbl->setJustificationType (juce::Justification::centred);
    PhaseMOD1Lbl->setEditable (false, false, false);
    PhaseMOD1Lbl->setColour (juce::Label::textColourId, juce::Colour (0xffffdf5e));
    PhaseMOD1Lbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    PhaseMOD1Lbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    PhaseMOD1Lbl->setBounds (198, 306, 56, 24);

    ModModeBtn.reset (new juce::TextButton ("Mod Mode Button"));
    addAndMakeVisible (ModModeBtn.get());
    ModModeBtn->setTooltip (TRANS("Modulation mode: \"Blend\" applies both vowels in parallel and blends between the two, \"Freq\" applies a single vowel which is some combination of the two selected"));
    ModModeBtn->setButtonText (TRANS("Blend"));
    ModModeBtn->addListener (this);
    ModModeBtn->setColour (juce::TextButton::buttonColourId, juce::Colour (0xffffcc00));
    ModModeBtn->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xffff5032));
    ModModeBtn->setColour (juce::TextButton::textColourOffId, juce::Colour (0xffffcc00));
    ModModeBtn->setColour (juce::TextButton::textColourOnId, juce::Colour (0xffff5032));

    ModModeBtn->setBounds (181, 136, 64, 24);

    MixLbl.reset (new juce::Label ("Mix Label",
                                   TRANS("Mix")));
    addAndMakeVisible (MixLbl.get());
    MixLbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    MixLbl->setJustificationType (juce::Justification::centred);
    MixLbl->setEditable (false, false, false);
    MixLbl->setColour (juce::Label::textColourId, juce::Colour (0xffff8773));
    MixLbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    MixLbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    MixLbl->setBounds (95, 176, 32, 24);

    ModeLbl.reset (new juce::Label ("Mode Label",
                                    TRANS("Mode")));
    addAndMakeVisible (ModeLbl.get());
    ModeLbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    ModeLbl->setJustificationType (juce::Justification::centred);
    ModeLbl->setEditable (false, false, false);
    ModeLbl->setColour (juce::Label::textColourId, juce::Colour (0xffff8773));
    ModeLbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    ModeLbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    ModeLbl->setBounds (190, 176, 46, 24);

    OutputGainSld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("Output Gain Slider"));
    addAndMakeVisible (OutputGainSld.get());
    OutputGainSld->setTooltip (TRANS("Output gain"));
    OutputGainSld->setRange (0, 1, 0.01);
    OutputGainSld->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    OutputGainSld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    OutputGainSld->addListener (this);

    OutputGainSld->setBounds (278, 117, 72, 56);

    OutputGainLbl.reset (new juce::Label ("Output Gain Label",
                                          TRANS("Output Gain")));
    addAndMakeVisible (OutputGainLbl.get());
    OutputGainLbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    OutputGainLbl->setJustificationType (juce::Justification::centred);
    OutputGainLbl->setEditable (false, false, false);
    OutputGainLbl->setColour (juce::Label::textColourId, juce::Colour (0xffff8773));
    OutputGainLbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    OutputGainLbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    OutputGainLbl->setBounds (270, 176, 88, 24);

    FilterPosLbl.reset (new juce::Label ("Filter Position Label",
                                         juce::String()));
    addAndMakeVisible (FilterPosLbl.get());
    FilterPosLbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    FilterPosLbl->setJustificationType (juce::Justification::centred);
    FilterPosLbl->setEditable (false, false, false);
    FilterPosLbl->setColour (juce::Label::textColourId, juce::Colour (0xffff8773));
    FilterPosLbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    FilterPosLbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    FilterPosLbl->setBounds (192, 88, 46, 24);

    WaveViewMOD1.reset (new WECore::Richter::WaveViewer());
    addAndMakeVisible (WaveViewMOD1.get());
    WaveViewMOD1->setName ("MOD1 Wave View");

    WaveViewMOD1->setBounds (261, 276, 75, 23);


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
    TempoSyncMOD1Btn->setLookAndFeel(&yellowLookAndFeel);
    PhaseSyncMOD1Btn->setLookAndFeel(&yellowLookAndFeel);
    WaveViewMOD1->setLookAndFeel(&yellowLookAndFeel);

    WaveMOD1Cmb->setColour(ComboBox::ColourIds::textColourId, lightYellow);
    WaveMOD1Cmb->setColour(ComboBox::ColourIds::arrowColourId, lightYellow);

    TempoNumerMOD1Sld->setLookAndFeel(&tempoButtonLookAndFeel);
    TempoDenomMOD1Sld->setLookAndFeel(&tempoButtonLookAndFeel);

    // Wave viewer colour
    yellowLookAndFeel.setColour(WECore::Richter::WaveViewer::ColourIds::highlightColourId,
                                yellowHighlight);

    // This is needed for the fonts to be applied
    SongbirdLookAndFeel::setDefaultLookAndFeel(&yellowLookAndFeel);

    startTimer(40);

    // Make tempo sync buttons draggable
    TempoNumerMOD1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
    TempoDenomMOD1Sld->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);

    _enableDoubleClickToDefault();

    _startSliderReadouts();

    // Call this manually once to make sure the UI reflects the parameters' states correctly
    _onParameterUpdate();
    //[/Constructor]
}

SongbirdAudioProcessorEditor::~SongbirdAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    _stopSliderReadouts();

    WaveViewMOD1->stop();
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
    OutputGainSld = nullptr;
    OutputGainLbl = nullptr;
    FilterPosLbl = nullptr;
    WaveViewMOD1 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    _removeLookAndFeelFromAllChildren();
    //[/Destructor]
}

//==============================================================================
void SongbirdAudioProcessorEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colours::white);

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

void SongbirdAudioProcessorEditor::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    SongbirdAudioProcessor* ourProcessor {getProcessor()};
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == Vowel1Cmb.get())
    {
        //[UserComboBoxCode_Vowel1Cmb] -- add your combo box handling code here..
        ourProcessor->setVowel1(Vowel1Cmb->getSelectedId());
        //[/UserComboBoxCode_Vowel1Cmb]
    }
    else if (comboBoxThatHasChanged == Vowel2Cmb.get())
    {
        //[UserComboBoxCode_Vowel2Cmb] -- add your combo box handling code here..
        ourProcessor->setVowel2(Vowel2Cmb->getSelectedId());
        //[/UserComboBoxCode_Vowel2Cmb]
    }
    else if (comboBoxThatHasChanged == WaveMOD1Cmb.get())
    {
        //[UserComboBoxCode_WaveMOD1Cmb] -- add your combo box handling code here..
        ourProcessor->setWaveMOD1(WaveMOD1Cmb->getSelectedId());
        //[/UserComboBoxCode_WaveMOD1Cmb]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void SongbirdAudioProcessorEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    SongbirdAudioProcessor* ourProcessor {getProcessor()};
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == FilterPosSld.get())
    {
        //[UserSliderCode_FilterPosSld] -- add your slider handling code here..
        ourProcessor->setFilterPosition(FilterPosSld->getValue());
        //[/UserSliderCode_FilterPosSld]
    }
    else if (sliderThatWasMoved == MixSld.get())
    {
        //[UserSliderCode_MixSld] -- add your slider handling code here..
        ourProcessor->setMix(MixSld->getValue());
        //[/UserSliderCode_MixSld]
    }
    else if (sliderThatWasMoved == DepthMOD1Sld.get())
    {
        //[UserSliderCode_DepthMOD1Sld] -- add your slider handling code here..
        ourProcessor->setDepthMOD1(DepthMOD1Sld->getValue());
        //[/UserSliderCode_DepthMOD1Sld]
    }
    else if (sliderThatWasMoved == FreqMOD1Sld.get())
    {
        //[UserSliderCode_FreqMOD1Sld] -- add your slider handling code here..
        ourProcessor->setFreqMOD1(FreqMOD1Sld->getValue());
        //[/UserSliderCode_FreqMOD1Sld]
    }
    else if (sliderThatWasMoved == TempoNumerMOD1Sld.get())
    {
        //[UserSliderCode_TempoNumerMOD1Sld] -- add your slider handling code here..
        ourProcessor->setTempoNumerMOD1(TempoNumerMOD1Sld->getValue());
        //[/UserSliderCode_TempoNumerMOD1Sld]
    }
    else if (sliderThatWasMoved == TempoDenomMOD1Sld.get())
    {
        //[UserSliderCode_TempoDenomMOD1Sld] -- add your slider handling code here..
        ourProcessor->setTempoDenomMOD1(TempoDenomMOD1Sld->getValue());
        //[/UserSliderCode_TempoDenomMOD1Sld]
    }
    else if (sliderThatWasMoved == PhaseMOD1Sld.get())
    {
        //[UserSliderCode_PhaseMOD1Sld] -- add your slider handling code here..
        ourProcessor->setPhaseMOD1(PhaseMOD1Sld->getValue());
        //[/UserSliderCode_PhaseMOD1Sld]
    }
    else if (sliderThatWasMoved == OutputGainSld.get())
    {
        //[UserSliderCode_OutputGainSld] -- add your slider handling code here..
        ourProcessor->setOutputGain(OutputGainSld->getValue());
        //[/UserSliderCode_OutputGainSld]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void SongbirdAudioProcessorEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    SongbirdAudioProcessor* ourProcessor {getProcessor()};
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == TempoSyncMOD1Btn.get())
    {
        //[UserButtonCode_TempoSyncMOD1Btn] -- add your button handler code here..
        ourProcessor->setTempoSyncMOD1(!TempoSyncMOD1Btn->getToggleState());
        //[/UserButtonCode_TempoSyncMOD1Btn]
    }
    else if (buttonThatWasClicked == PhaseSyncMOD1Btn.get())
    {
        //[UserButtonCode_PhaseSyncMOD1Btn] -- add your button handler code here..
        ourProcessor->setPhaseSyncMOD1(!PhaseSyncMOD1Btn->getToggleState());
        //[/UserButtonCode_PhaseSyncMOD1Btn]
    }
    else if (buttonThatWasClicked == ModModeBtn.get())
    {
        //[UserButtonCode_ModModeBtn] -- add your button handler code here..
        ourProcessor->setModMode(!ModModeBtn->getToggleState());
        //[/UserButtonCode_ModModeBtn]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void SongbirdAudioProcessorEditor::sliderDragStarted(Slider* slider) {
    SongbirdAudioProcessor* ourProcessor {getProcessor()};

    if (slider == FilterPosSld.get()) {
        ourProcessor->filterPosition->beginChangeGesture();
    } else if (slider == MixSld.get()) {
        ourProcessor->mix->beginChangeGesture();
    } else if (slider == DepthMOD1Sld.get()) {
        ourProcessor->depthMOD1->beginChangeGesture();
    } else if (slider == FreqMOD1Sld.get()) {
        ourProcessor->freqMOD1->beginChangeGesture();
    } else if (slider == TempoNumerMOD1Sld.get()) {
        ourProcessor->tempoNumerMOD1->beginChangeGesture();
    } else if (slider == TempoDenomMOD1Sld.get()) {
        ourProcessor->tempoDenomMOD1->beginChangeGesture();
    } else if (slider == PhaseMOD1Sld.get()) {
        ourProcessor->phaseMOD1->beginChangeGesture();
    } else if (slider == OutputGainSld.get()) {
        ourProcessor->outputGain->beginChangeGesture();
    }
}

void SongbirdAudioProcessorEditor::sliderDragEnded(Slider* slider) {
    SongbirdAudioProcessor* ourProcessor {getProcessor()};

    if (slider == FilterPosSld.get()) {
        ourProcessor->filterPosition->endChangeGesture();
    } else if (slider == MixSld.get()) {
        ourProcessor->mix->endChangeGesture();
    } else if (slider == DepthMOD1Sld.get()) {
        ourProcessor->depthMOD1->endChangeGesture();
    } else if (slider == FreqMOD1Sld.get()) {
        ourProcessor->freqMOD1->endChangeGesture();
    } else if (slider == TempoNumerMOD1Sld.get()) {
        ourProcessor->tempoNumerMOD1->endChangeGesture();
    } else if (slider == TempoDenomMOD1Sld.get()) {
        ourProcessor->tempoDenomMOD1->endChangeGesture();
    } else if (slider == PhaseMOD1Sld.get()) {
        ourProcessor->phaseMOD1->endChangeGesture();
    } else if (slider == OutputGainSld.get()) {
        ourProcessor->outputGain->endChangeGesture();
    }
}

void SongbirdAudioProcessorEditor::timerCallback() {
    SongbirdAudioProcessor* ourProcessor {getProcessor()};

    // Pickup LFO output value
    orangeLookAndFeel.updateLFOOutput(ourProcessor->getLastLFOOutput());
    FilterPosSld->repaint();
}

void SongbirdAudioProcessorEditor::_onParameterUpdate() {
    SongbirdAudioProcessor* ourProcessor {getProcessor()};

    Vowel1Cmb->setSelectedId(ourProcessor->vowel1->get(), dontSendNotification);
    Vowel2Cmb->setSelectedId(ourProcessor->vowel2->get(), dontSendNotification);
    FilterPosSld->setValue(ourProcessor->filterPosition->get(), dontSendNotification);
    MixSld->setValue(ourProcessor->mix->get(), dontSendNotification);
    ModModeBtn->setToggleState(ourProcessor->modMode->get(), dontSendNotification);
    OutputGainSld->setValue(ourProcessor->outputGain->get(), dontSendNotification);

    // Set text and label colour for mod mode button
    ModModeBtn->getToggleState() ? ModModeBtn->setButtonText("FREQ") :
                                    ModModeBtn->setButtonText("BLEND");

    const Colour modeLabelColour = Colour(ModModeBtn->getToggleState() ? 0xffff8773 : 0xffffdf5e);
    ModeLbl->setColour(Label::textColourId, modeLabelColour);

    // MOD 1
    PhaseSyncMOD1Btn->setToggleState(ourProcessor->phaseSyncMOD1->get(), dontSendNotification);
    TempoSyncMOD1Btn->setToggleState(ourProcessor->tempoSyncMOD1->get(), dontSendNotification);
    WaveMOD1Cmb->setSelectedId(ourProcessor->waveMOD1->get(), dontSendNotification);
    DepthMOD1Sld->setValue(ourProcessor->depthMOD1->get(), dontSendNotification);
    FreqMOD1Sld->setValue(ourProcessor->freqMOD1->get(), dontSendNotification);
    PhaseMOD1Sld->setValue(ourProcessor->phaseMOD1->get(), dontSendNotification);
    TempoNumerMOD1Sld->setValue(ourProcessor->tempoNumerMOD1->get(), dontSendNotification);
    TempoDenomMOD1Sld->setValue(ourProcessor->tempoDenomMOD1->get(), dontSendNotification);

    // Activate/Deactivate phase control depending on phase sync
    PhaseMOD1Sld->setEnabled(PhaseSyncMOD1Btn->getToggleState());

    const Colour phaseLabelColour = PhaseSyncMOD1Btn->getToggleState() ?
            Colour(0xffffdf5e) : PhaseMOD1Sld->findColour(Slider::rotarySliderOutlineColourId);

    PhaseMOD1Lbl->setColour(Label::textColourId, phaseLabelColour);


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

    // Update wave viewer
    if (ourProcessor->waveMOD1->get() == 1) {
        WaveViewMOD1->setWave(WECore::Richter::Wavetables::getInstance()->getSine());
    } else if (ourProcessor->waveMOD1->get() == 2) {
        WaveViewMOD1->setWave(WECore::Richter::Wavetables::getInstance()->getSquare());
    } else if (ourProcessor->waveMOD1->get() == 3) {
        WaveViewMOD1->setWave(WECore::Richter::Wavetables::getInstance()->getSaw());
    } else {
        WaveViewMOD1->setWave(WECore::Richter::Wavetables::getInstance()->getSidechain());
    }

    WaveViewMOD1->repaint();
}

void SongbirdAudioProcessorEditor::_enableDoubleClickToDefault() {
    FilterPosSld->setDoubleClickReturnValue(true,
        WECore::Songbird::Parameters::FILTER_POSITION.InternalToNormalised(WECore::Songbird::Parameters::FILTER_POSITION.defaultValue));
    MixSld->setDoubleClickReturnValue(true,
        WECore::Songbird::Parameters::MIX.InternalToNormalised(WECore::Songbird::Parameters::MIX.defaultValue));
    OutputGainSld->setDoubleClickReturnValue(true,
        WECore::Songbird::Parameters::OUTPUTGAIN.InternalToNormalised(WECore::Songbird::Parameters::OUTPUTGAIN.defaultValue));

    FreqMOD1Sld->setDoubleClickReturnValue(true,
        WECore::Richter::Parameters::FREQ.InternalToNormalised(WECore::Richter::Parameters::FREQ.defaultValue));
    DepthMOD1Sld->setDoubleClickReturnValue(true,
        WECore::Richter::Parameters::DEPTH.InternalToNormalised(WECore::Richter::Parameters::DEPTH.defaultValue));
    PhaseMOD1Sld->setDoubleClickReturnValue(true,
        WECore::Richter::Parameters::PHASE.InternalToNormalised(WECore::Richter::Parameters::PHASE.defaultValue));
}

void SongbirdAudioProcessorEditor::_startSliderReadouts() {
    FilterPosSld->start(FilterPosLbl.get(), FilterPosLbl->getText(), &WECore::Songbird::Parameters::FILTER_POSITION);
    MixSld->start(MixLbl.get(), MixLbl->getText(), &WECore::Songbird::Parameters::MIX);
    OutputGainSld->start(OutputGainLbl.get(), OutputGainLbl->getText(), &WECore::Songbird::Parameters::OUTPUTGAIN);

    FreqMOD1Sld->start(FreqMOD1Lbl.get(), FreqMOD1Lbl->getText(), &WECore::Richter::Parameters::FREQ);
    DepthMOD1Sld->start(DepthMOD1Lbl.get(), DepthMOD1Lbl->getText(), &WECore::Richter::Parameters::DEPTH);
    PhaseMOD1Sld->start(PhaseMOD1Lbl.get(), PhaseMOD1Lbl->getText(), &PHASE_DISPLAY);
}

void SongbirdAudioProcessorEditor::_stopSliderReadouts() {
    FilterPosSld->stop();
    MixSld->stop();
    OutputGainSld->stop();

    FreqMOD1Sld->stop();
    DepthMOD1Sld->stop();
    PhaseMOD1Sld->stop();
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
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="425" initialHeight="350">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GROUPCOMPONENT name="MOD 1 Group" id="a2c7412d0fb46a58" memberName="MOD1Group"
                  virtualName="" explicitFocusOrder="0" pos="72 214 280 136" outlinecol="ffffdf5e"
                  textcol="ffffdf5e" title="LFO" textpos="36"/>
  <COMBOBOX name="Vowel 1 Combo Box" id="ab5acbd6ca836993" memberName="Vowel1Cmb"
            virtualName="" explicitFocusOrder="0" pos="60 64 48 24" tooltip="Vowel to apply in the left position"
            editable="0" layout="33" items="A&#10;E&#10;I&#10;O&#10;U" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="Filter Position Slider" id="1be87d051f6ceb97" memberName="FilterPosSld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="124 64 184 24" tooltip="Manully modulate between the two vowels using the mode selected below"
          min="0.0" max="1.0" int="0.01" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <COMBOBOX name="Vowel 2 Combo Box" id="9ac26013f2f51695" memberName="Vowel2Cmb"
            virtualName="" explicitFocusOrder="0" pos="316 64 48 24" tooltip="Vowel to apply in the right position"
            editable="0" layout="33" items="A&#10;E&#10;I&#10;O&#10;U" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="Mix Slider" id="b75c053482d8ac35" memberName="MixSld" virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="75 117 72 56" tooltip="Dry/Wet mix level"
          min="0.0" max="1.0" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="MOD 1 Depth Slider" id="499f6451911662cc" memberName="DepthMOD1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="151 276 32 24" tooltip="Depth of the LFO"
          min="0.0" max="1.0" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="MOD 1 Freq Slider" id="1d9800ca18cf5bba" memberName="FreqMOD1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="92 276 32 24" tooltip="Frequency of the LFO, from 2Hz to 20Hz"
          min="0.0" max="1.0" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <COMBOBOX name="MOD 1 Wave" id="370e5062e67cf738" memberName="WaveMOD1Cmb"
            virtualName="" explicitFocusOrder="0" pos="259 306 80 24" tooltip="LFO wave shape"
            editable="0" layout="33" items="Sine&#10;Square&#10;Saw&#10;SC Comp"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="MOD 1 Freq Label" id="dabfca26c640fd58" memberName="FreqMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="80 306 56 24" textCol="ffffdf5e"
         edTextCol="ff000000" edBkgCol="0" labelText="Rate" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="MOD 1 Depth Label" id="77092a4a55225c68" memberName="DepthMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="139 306 54 24" textCol="ffffdf5e"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
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
              virtualName="" explicitFocusOrder="0" pos="199 242 54 16" tooltip="Enable phase sync to ensure the phase of the LFO is consistent regardless of where the DAW playhead starts from"
              buttonText="Phase" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="MOD 1 Phase Slider" id="3f1ef3d10c303bac" memberName="PhaseMOD1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="210 276 32 24" tooltip="Phase shift the LFO by up to 360 degrees"
          min="0.0" max="1.0" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="MOD 1 Phase Label" id="af1abf98d305cb5c" memberName="PhaseMOD1Lbl"
         virtualName="" explicitFocusOrder="0" pos="198 306 56 24" textCol="ffffdf5e"
         edTextCol="ff000000" edBkgCol="0" labelText="Phase" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="Mod Mode Button" id="82ccbd2e4873bcd5" memberName="ModModeBtn"
              virtualName="" explicitFocusOrder="0" pos="181 136 64 24" tooltip="Modulation mode: &quot;Blend&quot; applies both vowels in parallel and blends between the two, &quot;Freq&quot; applies a single vowel which is some combination of the two selected"
              bgColOff="ffffcc00" bgColOn="ffff5032" textCol="ffffcc00" textColOn="ffff5032"
              buttonText="Blend" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="Mix Label" id="49736b42e5833ce0" memberName="MixLbl" virtualName=""
         explicitFocusOrder="0" pos="95 176 32 24" textCol="ffff8773"
         edTextCol="ff000000" edBkgCol="0" labelText="Mix" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="Mode Label" id="8aeac08f9afe843a" memberName="ModeLbl"
         virtualName="" explicitFocusOrder="0" pos="190 176 46 24" textCol="ffff8773"
         edTextCol="ff000000" edBkgCol="0" labelText="Mode" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="Output Gain Slider" id="69d51698f3b89634" memberName="OutputGainSld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="278 117 72 56" tooltip="Output gain"
          min="0.0" max="1.0" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Output Gain Label" id="fe76b3e123fa3f5" memberName="OutputGainLbl"
         virtualName="" explicitFocusOrder="0" pos="270 176 88 24" textCol="ffff8773"
         edTextCol="ff000000" edBkgCol="0" labelText="Output Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="Filter Position Label" id="1b9fe7c323e1b093" memberName="FilterPosLbl"
         virtualName="" explicitFocusOrder="0" pos="192 88 46 24" textCol="ffff8773"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <GENERICCOMPONENT name="MOD1 Wave View" id="3c0e47dfa5180365" memberName="WaveViewMOD1"
                    virtualName="WECore::Richter::WaveViewer" explicitFocusOrder="0"
                    pos="261 276 75 23" class="juce::Component" params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

