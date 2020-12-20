#!/bin/bash

set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" > /dev/null 2>&1 && pwd )"

# Download WE-Core
echo "=== Cloning WE-Core ==="
WECORE_HOME=$SCRIPT_DIR/../WECore
git clone https://github.com/jd-13/WE-Core $WECORE_HOME

cd $WECORE_HOME
echo "=== Using WE-Core $(git log --pretty=format:'%h' -n 1) ==="
cd -

echo "=== Downloading fonts ==="
wget https://github.com/JulietaUla/Montserrat/raw/master/fonts/ttf/Montserrat-Regular.ttf \
     -P $SCRIPT_DIR/../Source/Graphics

# Set JUCE module paths
echo "=== Setting module paths ==="
sed -i 's#../JUCE/modules#/home/JUCE/modules#g' $SCRIPT_DIR/../Songbird.jucer

# Generate the makefile
echo "=== Generating makefile ==="
$JUCE_PATH/Projucer --resave $SCRIPT_DIR/../Songbird.jucer

# Update the include paths
echo "=== Updating include paths ==="
sed -i 's#-I$(HOME)/WEA/WECore/WECore#-I../../WECore/WECore#g' $SCRIPT_DIR/../Builds/LinuxMakefile/Makefile

# Run the build
echo "=== Starting build ==="
cd $SCRIPT_DIR/../Builds/LinuxMakefile
make
