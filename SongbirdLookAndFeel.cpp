/*
  ==============================================================================

    SongbirdLookAndFeel.cpp
    Created: 7 Sep 2016 11:43:29pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "SongbirdLookAndFeel.h"

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

    g.setColour(darkColour);
    p.addEllipse(sliderPos - sliderThumbRadius,
                 height / 2 - sliderThumbRadius,
                 sliderThumbRadius * 2,
                 sliderThumbRadius * 2);
    g.fillPath(p);

    drawThumbHalf(highlightColour, M_PI);
    drawThumbHalf(highlightColour2, 0);
    
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
        g.setColour(highlightColour2);
        g.fillRect(x, y + height / 2, width, 2);
        
        g.setColour(highlightColour);
        g.fillRect(x, y + height / 2, static_cast<int>(sliderPos) , 2);
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
    Colour& vowelColour {highlightColour};
    
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
        
        g.setColour(box.isPopupActive() ? vowelColour : lightColour);
        
        g.fillPath(p);
    }
    
    const float indent {2.0f};
    const int cornerSize {jmin (roundToInt(width * 0.2f),
                                roundToInt(height * 0.2f))};
    
    Path p;
    PathStrokeType pStroke(1);
    
    
    p.addRoundedRectangle(indent, indent, width - 2 * indent, height - 2 * indent, static_cast<float>(cornerSize));

    
    g.setColour(vowelColour);
    g.strokePath(p, pStroke);
    
}