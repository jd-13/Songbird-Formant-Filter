/*
  ==============================================================================

    SongbirdLookAndFeel.cpp
    Created: 7 Sep 2016 11:43:29pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "SongbirdLookAndFeel.h"

SongbirdLookAndFeel::SongbirdLookAndFeel() :    LookAndFeel_V2(),
                                                lightGrey(200, 200, 200),
                                                darkGrey(107, 107, 107),
                                                deepBlue(71, 55, 219),
                                                deepRed(222, 35, 35),
                                                vowel1Colour(deepBlue),
                                                vowel2Colour(deepRed) {
    
    setColour(PopupMenu::highlightedBackgroundColourId, darkGrey);
    setColour(PopupMenu::backgroundColourId, lightGrey);
}

void SongbirdLookAndFeel::drawRotarySlider(Graphics& g,
                                             int /*x*/,
                                             int /*y*/,
                                             int width,
                                             int height,
                                             float /*sliderPosProportional*/,
                                             float /*rotaryStartAngle*/,
                                             float /*rotaryEndAngle*/,
                                             Slider &slider) {
    // calculate useful constants
    const double rangeOfMotion {260 * (M_PI / 180)};
    const double rotation {((slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum())) * rangeOfMotion - rangeOfMotion / 2};
    
    const int margin {1};
    const float diameter {static_cast<float>(height - margin * 2)};
    
    // draw centre circle
    Path p;
    g.setColour(darkGrey);
    p.addEllipse(width / 2 - diameter / 2, height / 2 - diameter / 2, diameter, diameter);
    g.fillPath(p);
    
    // draw outer ring
    if (slider.isEnabled()) {
        g.setColour(deepBlue);
    } else {
        g.setColour(lightGrey);
    }
    
    p.clear();
    
    const double gap {0.4};
    p.addCentredArc(width / 2, height / 2, diameter / 2, diameter / 2, rotation, gap, 2 * M_PI - gap, true);
    
    g.strokePath(p, PathStrokeType(2.0f));
    
}

void SongbirdLookAndFeel::drawLinearSliderThumb(Graphics& g,
                                                int /*x*/,
                                                int /*y*/,
                                                int /*width*/,
                                                int height,
                                                float sliderPos,
                                                float /*minSliderPos*/,
                                                float /*maxSliderPos*/,
                                                const Slider::SliderStyle /*style*/,
                                                Slider& /*slider*/) {
    
    
    Path p;
    const float lineWidth {1.5f};
    const float sliderThumbRadius {5};
    
    auto drawThumbHalf = [&g,
                          &p,
                          height,
                          sliderThumbRadius,
                          sliderPos,
                          lineWidth](Colour colour, double rotation) -> void {
        p.clear();
        g.setColour(colour);
        p.addCentredArc(sliderPos,
                        height / 2,
                        sliderThumbRadius,
                        sliderThumbRadius,
                        rotation,
                        0,
                        M_PI,
                        true);
        g.strokePath(p, PathStrokeType(lineWidth));
    };

    g.setColour(darkGrey);
    p.addEllipse(sliderPos - sliderThumbRadius,
                 height / 2 - sliderThumbRadius,
                 sliderThumbRadius * 2,
                 sliderThumbRadius * 2);
    g.fillPath(p);

    drawThumbHalf(vowel1Colour, M_PI);
    drawThumbHalf(vowel2Colour, 0);
    
}

void SongbirdLookAndFeel::drawLinearSliderBackground(Graphics& g,
                                                     int x,
                                                     int y,
                                                     int width,
                                                     int height,
                                                     float sliderPos,
                                                     float /*minSliderPos*/,
                                                     float /*maxSliderPos*/,
                                                     const Slider::SliderStyle /*style*/,
                                                     Slider& slider) {
    
    // NOTE: assumes the only horizontal slider is the filter position
    if (slider.isHorizontal()) {
        // colour the side of the background on either side of the thumb differently
        g.setColour(deepBlue);
        g.fillRect(x, y + height / 2, static_cast<int>(sliderPos), 2);
        
        g.setColour(deepRed);
        g.fillRect(static_cast<int>(sliderPos), y + height / 2, width, 2);
    }
}

void SongbirdLookAndFeel::drawComboBox(Graphics& g,
                                    int width,
                                    int height,
                                    const bool /*isButtonDown*/,
                                    int buttonX,
                                    int buttonY,
                                    int buttonW,
                                    int buttonH,
                                    ComboBox& box) {
    
    // determine correct colour
    Colour* vowelColour {nullptr};
    if (box.getName() == "Vowel 1 Combo Box") {
        vowelColour = &vowel1Colour;
    } else {
        vowelColour = &vowel2Colour;
    }
    
    // draw arrows
    const float arrowX {0.2f};
    const float arrowH {0.3f};
    
    if (box.isEnabled()) {
        Path p;
        p.addTriangle(buttonX + buttonW * 0.5f,                 buttonY + buttonH * (0.45f - arrowH),
                      buttonX + buttonW * (1.0f - arrowX),      buttonY + buttonH * 0.45f,
                      buttonX + buttonW * arrowX,               buttonY + buttonH * 0.45f);
        
        p.addTriangle(buttonX + buttonW * 0.5f,                 buttonY + buttonH * (0.55f + arrowH),
                      buttonX + buttonW * (1.0f -arrowX),       buttonY + buttonH * 0.55f,
                      buttonX + buttonW * arrowX,               buttonY + buttonH * 0.55f);
        
        g.setColour(box.isPopupActive() ? *vowelColour : lightGrey);
        
        g.fillPath(p);
    }
    
    const float indent {2.0f};
    const int cornerSize {jmin (roundToInt(width * 0.2f),
                                roundToInt(height * 0.2f))};
    
    Path p;
    PathStrokeType pStroke(1);
    
    
    p.addRoundedRectangle(indent, indent, width - 2 * indent, height - 2 * indent, static_cast<float>(cornerSize));

    
    g.setColour(*vowelColour);
    g.strokePath(p, pStroke);
    
}