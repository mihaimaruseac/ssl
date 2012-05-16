#!/bin/bash
# Use the standard model

pushd gen &> /dev/null

./supervised-gen.bash 10
./svm-prepare.bash

popd &> /dev/null

svm/svm-predict tset std.model out; cat out | gen2svm/svm2out

