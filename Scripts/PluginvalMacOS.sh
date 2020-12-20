#!/bin/bash

set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" > /dev/null 2>&1 && pwd )"

echo "=== Downloading Pluginval ==="
wget https://github.com/Tracktion/pluginval/releases/download/v0.2.9/pluginval_macOS.zip \
     -P $SCRIPT_DIR/..

unzip pluginval_macOS.zip
PLUGINVAL=pluginval.app/Contents/MacOS/pluginval

echo "=== Testing AU ==="
$PLUGINVAL --validate $SCRIPT_DIR/../Builds/MacOSX/build/Debug/Songbird.component \
           --strictness-level 10 \
           --skip-gui-tests

echo "=== Testing VST3 ==="
# Exclude tests that don't work on VST3
cat << EOF >> $SCRIPT_DIR/disabled-tests.txt
Basic bus
EOF

$PLUGINVAL --validate $SCRIPT_DIR/../Builds/MacOSX/build/Debug/Songbird.vst3 \
           --strictness-level 10 \
           --skip-gui-tests \
           --disabled-tests $SCRIPT_DIR/disabled-tests.txt
