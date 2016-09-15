/*
  ==============================================================================

    SongbirdLookAndFeel.h
    Created: 7 Sep 2016 11:43:29pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef SONGBIRDLOOKANDFEEL_H_INCLUDED
#define SONGBIRDLOOKANDFEEL_H_INCLUDED

#define _USE_MATH_DEFINES

#include "math.h"
#include "../JuceLibraryCode/JuceHeader.h"



class SongbirdLookAndFeel : public LookAndFeel_V2 {
public:
    SongbirdLookAndFeel();
    
    virtual void drawRotarySlider(Graphics& g,
                                  int x,
                                  int y,
                                  int width,
                                  int height,
                                  float sliderPosProportional,
                                  float rotaryStartAngle,
                                  float rotaryEndAngle,
                                  Slider& slider) override;
    
    virtual void drawLinearSliderThumb(Graphics& g,
                                       int x,
                                       int y,
                                       int width,
                                       int height,
                                       float sliderPos,
                                       float minSliderPos,
                                       float maxSliderPos,
                                       const Slider::SliderStyle style,
                                       Slider& slider) override;
    
    virtual void drawLinearSliderBackground(Graphics& g,
                                            int x,
                                            int y,
                                            int width,
                                            int height,
                                            float sliderPos,
                                            float minSliderPos,
                                            float maxSliderPos,
                                            const Slider::SliderStyle style,
                                            Slider& slider) override;
    
    virtual void drawComboBox(Graphics& g,
                              int width,
                              int height,
                              const bool isButtonDown,
                              int buttonX,
                              int buttonY,
                              int buttonW,
                              int buttonH,
                              ComboBox& box) override;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SongbirdLookAndFeel)
    
    Colour  lightGrey,
            darkGrey,
            deepBlue,
            deepRed;
    
    Colour  &vowel1Colour,
            &vowel2Colour;
    
};

#endif  // SONGBIRDLOOKANDFEEL_H_INCLUDED
