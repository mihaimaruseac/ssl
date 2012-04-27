#!/bin/bash
# Use libSVM to get a model of the generated images

pushd svm/tools &> /dev/null

./easy.py ../../tset
mv tset* ../../

popd &> /dev/null
