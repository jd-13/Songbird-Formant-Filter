/*
 *	File:		SongbirdLookAndFeel.cpp
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

#include "SongbirdLookAndFeel.h"

SongbirdLookAndFeel::SongbirdLookAndFeel() : _highlightColour2(Colour(222, 35, 35)),
                                             _lfoOutput(0) {
}

void SongbirdLookAndFeel::setHighlightColour(Colour newColour) {
    SongbirdLookAndFeelBase::setHighlightColour(newColour);
    setColour(ComboBox::textColourId, highlightColour);
}

void SongbirdLookAndFeel::setHighlightColours(Colour newColour1, Colour newColour2) {
    setHighlightColour(newColour1);
    _highlightColour2 = newColour2;
}

void SongbirdLookAndFeel::updateLFOOutput(double value) {
    _lfoOutput = value;
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
    constexpr float lineWidth {1.5f};
    
    auto drawThumbHalf = [&g,
                          &p,
                          height,
                          sliderPos,
                          lineWidth](Colour colour,
                                     double rotation,
                                     float sliderThumbRadius) -> void {
        p.clear();
        g.setColour(colour);
        p.addCentredArc(sliderPos,
                        height / 2,
                        sliderThumbRadius,
                        sliderThumbRadius,
                        rotation,
                        0,
                        CoreMath::DOUBLE_PI,
                        true);
        g.strokePath(p, PathStrokeType(lineWidth));
    };

    g.setColour(darkColour);
    g.fillPath(p);

    drawThumbHalf(highlightColour, CoreMath::DOUBLE_PI, _sliderThumbRadius);
    drawThumbHalf(_highlightColour2, 0, _sliderThumbRadius);
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
        
        // Colour the side of the background on either side of the thumb differently
        constexpr int lineThickness {2};
        const int lineY {(y + height / 2) - (lineThickness / 2)};
        
        // Draw the red half
        const int greenLength {static_cast<int>(sliderPos - _sliderThumbRadius - x)};
        
        if (greenLength > 0) {
            g.setColour(highlightColour);
            g.fillRect(x, lineY, greenLength, lineThickness);
        }
        
        // Draw the yellow half
        const int yellowStartX {static_cast<int>(sliderPos + _sliderThumbRadius)};
        const int yellowLength {width - yellowStartX + x};
        
        if (yellowLength > 0) {
            g.setColour(_highlightColour2);
            g.fillRect(yellowStartX, lineY, yellowLength, lineThickness);
        }
        
        // Draw in the modulation line
        constexpr int modLineThickness {1};
        const int modOffset {static_cast<int>((_lfoOutput * width))};
        
        // Alternate colours above and below 0
        if (modOffset < 0) {
            g.setColour(highlightColour);
        } else {
            g.setColour(_highlightColour2);
        }
        
        g.fillRect(static_cast<int>(sliderPos),
                   y + height - 2,
                   modOffset,
                   modLineThickness);
        
    } else {
        assert(false && "Unsupported slider type");
    }
}

void SongbirdLookAndFeel::drawGroupComponentOutline(Graphics& g,
                                                    int width,
                                                    int height,
                                                    const String& text,
                                                    const Justification& /*justification*/,
                                                    GroupComponent& group) {
    
    constexpr int MARGIN {2};
    
    g.setColour(group.findColour(GroupComponent::textColourId));
    
    // Draw the text
    Font font;
    font.setTypefaceName("Courier New");
    g.setFont(font);
    
    g.drawText(text,
               (width / 2) - 12,
               MARGIN,
               width,
               height,
               Justification::topLeft,
               true);
    
    // Draw the separator
    const Colour outlineColour = group.findColour(GroupComponent::outlineColourId);
    const int textCentreX {width / 2};
    const int lineGap {34};
    const int lineThickness {1};
    const int lineLength {(width / 2) - (lineGap / 2) - MARGIN};
    const int lineY {static_cast<int>(
                        MARGIN + (font.getHeight() / 2) - (lineThickness / 2)
                     )};
    
    
    g.setGradientFill(ColourGradient(outlineColour,
                                     textCentreX,
                                     lineY,
                                     outlineColour.withAlpha(0.0f),
                                     0,
                                     lineY,
                                     true));
    
    g.fillRect(textCentreX - (lineGap / 2), lineY, -lineLength, lineThickness);
    g.drawRect(textCentreX + (lineGap / 2), lineY, lineLength, lineThickness);
}
