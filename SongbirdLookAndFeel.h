/*
 *	File:		SongbirdLookAndFeel.h
 *
 *	Version:	1.0.0
 *
 *	Created:	07/09/2016
 *
 *	This file is part of Songbird.
 *
 *  Songbird is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Songbird is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Songbird.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef SONGBIRDLOOKANDFEEL_H_INCLUDED
#define SONGBIRDLOOKANDFEEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "CoreJUCEPlugin/CoreLookAndFeel.h"

class SongbirdLookAndFeel : public WECore::JUCEPlugin::CoreLookAndFeel {
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
