[![CI Main](https://github.com/jd-13/Songbird-Formant-Filter/workflows/CI%20Main/badge.svg)](https://github.com/jd-13/Songbird-Formant-Filter/actions?query=workflow%3A%22CI+Main%22)
![](https://img.shields.io/badge/C%2B%2B-17-informational)
![](https://img.shields.io/badge/license-GPLv3-informational)

# Songbird-Formant-Filter
A VST and Audio Unit, which provides two formant filters and an LFO modulated blend control between the two.

For more details and a free download of the compiled plugin: https://www.whiteelephantaudio.com/plugins/songbird  

![](https://whiteelephantaudio.com/images/thumbs/originals/songbirdFull.png)  

## Built using:
JUCE: https://www.juce.com/

WECore: https://github.com/jd-13/WE-Core

Catch (for tests): https://github.com/philsquared/Catch

VST SDK: https://www.steinberg.net/en/company/developers.html

Vector images from https://www.Vecteezy.com

## Build Instructions

Like other JUCE applications, Songbird is built using the Projucer. There are however 2 steps needed
before it will build successfully:

1. Update the header search paths to point to the location of WECore on your machine
2. Download the font [Montserrat](https://fonts.google.com/specimen/Montserrat) and place the
regular ttf file in Source/Graphics
