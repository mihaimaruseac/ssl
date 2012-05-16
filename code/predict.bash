#!/bin/bash
# Test the accuracy of a model

IMGDIR="examples"
NUM_TESTS="100"

echo -n "Generating images..."

# move to gen
pushd gen &> /dev/null
rm -rf "$IMGDIR"
./supervised-gen.bash "$NUM_TESTS"
echo "done"

echo -ne "Preparing for svm..."
./svm-prepare.bash
echo "done"
popd &> /dev/null

svm/svm-predict tset tset.model out
