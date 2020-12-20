#!/bin/bash

set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" > /dev/null 2>&1 && pwd )"

echo "=== Cloning WE-Core ==="
WECORE_HOME=$SCRIPT_DIR/../WECore
git clone https://github.com/jd-13/WE-Core $WECORE_HOME

cd $WECORE_HOME
echo "=== Using WE-Core $(git log --pretty=format:'%h' -n 1) ==="
cd -

echo "=== Downloading fonts ==="
wget https://github.com/JulietaUla/Montserrat/raw/master/fonts/ttf/Montserrat-Regular.ttf \
     -P $SCRIPT_DIR/../Source/Graphics

echo "=== Downloading JUCE ==="
wget https://github.com/juce-framework/JUCE/releases/download/6.0.5/juce-6.0.5-osx.zip \
     -P $SCRIPT_DIR/..
unzip $SCRIPT_DIR/../juce-6.0.5-osx.zip

echo "=== Setting module paths ==="
sed -i '' -e 's#../../../../../SDKs/JUCE/modules#JUCE/modules#g' $SCRIPT_DIR/../Songbird.jucer

echo "=== Updating include paths ==="
sed -i '' -e 's#../../../WECore/WECore#../../WECore/WECore#g' $SCRIPT_DIR/../Songbird.jucer

echo "=== Generating project ==="
$SCRIPT_DIR/../JUCE/Projucer.app/Contents/MacOS/Projucer --resave $SCRIPT_DIR/../Songbird.jucer

echo "=== Starting build ==="
cd $SCRIPT_DIR/../Builds/MacOSX
xcodebuild -version
xcodebuild -project Songbird.xcodeproj -scheme "Songbird - All" -configuration Debug