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

SongbirdLookAndFeel::SongbirdLookAndFeel() : _highlightColour2(Colour(222, 35, 35)) {
}

void SongbirdLookAndFeel::setHighlightColour(Colour newColour) {
    WECore::LookAndFeelMixins::WEV2LookAndFeel::setHighlightColour(newColour);
    setColour(ComboBox::textColourId, highlightColour);
}

void SongbirdLookAndFeel::setHighlightColours(Colour newColour1, Colour newColour2) {
    setHighlightColour(newColour1);
    _highlightColour2 = newColour2;
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
        
        // Draw the green half
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
    }
}
