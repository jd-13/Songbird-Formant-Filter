/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.1

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
    : AudioProcessorEditor(ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (Vowel1Cmb = new ComboBox ("Vowel 1 Combo Box"));
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
    FilterPosSld->setRange (0, 1, 0);
    FilterPosSld->setSliderStyle (Slider::LinearHorizontal);
    FilterPosSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    FilterPosSld->addListener (this);

    addAndMakeVisible (Vowel2Cmb = new ComboBox ("Vowel 2 Combo Box"));
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
    MixSld->setRange (0, 1, 0);
    MixSld->setSliderStyle (Slider::RotaryVerticalDrag);
    MixSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    MixSld->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    LookAndFeel::setDefaultLookAndFeel(&customLookAndFeel);

    startTimer(200);
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
    //[/UserPaint]
}

void SongbirdAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    Vowel1Cmb->setBounds (24, 56, 48, 24);
    FilterPosSld->setBounds (88, 56, 184, 24);
    Vowel2Cmb->setBounds (280, 56, 48, 24);
    MixSld->setBounds (144, 104, 80, 72);
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

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void SongbirdAudioProcessorEditor::timerCallback() {
    SongbirdAudioProcessor* ourProcessor {getProcessor()};

    if (ourProcessor->NeedsUIUpdate()) {
        Vowel1Cmb->setSelectedId(ourProcessor->getParameter(SongbirdAudioProcessor::vowel1), dontSendNotification);
        Vowel2Cmb->setSelectedId(ourProcessor->getParameter(SongbirdAudioProcessor::vowel2), dontSendNotification);
        FilterPosSld->setValue(ourProcessor->getParameter(SongbirdAudioProcessor::filterPosition), dontSendNotification);
        MixSld->setValue(ourProcessor->getParameter(SongbirdAudioProcessor::mix), dontSendNotification);
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
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="SongbirdAudioProcessor&amp; ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <COMBOBOX name="Vowel 1 Combo Box" id="ab5acbd6ca836993" memberName="Vowel1Cmb"
            virtualName="" explicitFocusOrder="0" pos="24 56 48 24" editable="0"
            layout="33" items="A&#10;E&#10;I&#10;O&#10;U" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="Filter Position Slider" id="1be87d051f6ceb97" memberName="FilterPosSld"
          virtualName="" explicitFocusOrder="0" pos="88 56 184 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <COMBOBOX name="Vowel 2 Combo Box" id="9ac26013f2f51695" memberName="Vowel2Cmb"
            virtualName="" explicitFocusOrder="0" pos="280 56 48 24" editable="0"
            layout="33" items="A&#10;E&#10;I&#10;O&#10;U" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="Mix Slider" id="b75c053482d8ac35" memberName="MixSld" virtualName=""
          explicitFocusOrder="0" pos="144 104 80 72" min="0" max="1" int="0"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
