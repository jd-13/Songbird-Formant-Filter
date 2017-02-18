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
#include "CoreLookAndFeel.h"

class SongbirdLookAndFeel : public CoreLookAndFeel {
public:
    SongbirdLookAndFeel();
    
    virtual ~SongbirdLookAndFeel() = default;
    
    virtual void setHighlightColour(Colour newColour) override;
    
    void setHighlightColours(Colour newColour1, Colour newColour2);
    
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
    
    
    
protected:
    Colour highlightColour2;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SongbirdLookAndFeel)
    
};

class SongbirdButtonLookAndFeel : public SongbirdLookAndFeel {
public:
    SongbirdButtonLookAndFeel() :   SongbirdLookAndFeel() {
        lightColour = highlightColour2;
    }
    
    virtual ~SongbirdButtonLookAndFeel() {}
    
    
};

// needed for the small buttons on the tempo sync ratio, they look weird with a border
class SongbirdTempoButtonLookAndFeel : public SongbirdLookAndFeel {
public:
    SongbirdTempoButtonLookAndFeel() : SongbirdLookAndFeel() {}
    virtual ~SongbirdTempoButtonLookAndFeel() = default;
    
    virtual void drawButtonBackground(Graphics& /*g*/,
                                      Button& /*button*/,
                                      const Colour& /*backgroundColour*/,
                                      bool /*isMouseOverButton*/,
                                      bool /*isButtonDown*/) override {
        // do nothing
    }
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SongbirdTempoButtonLookAndFeel);
};

#endif  // SONGBIRDLOOKANDFEEL_H_INCLUDED
