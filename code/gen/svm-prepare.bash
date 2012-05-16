#!/bin/bash
# Generate CAPTCHA examples for supervised learning

IMGDIR="examples"
TSET="tset"
> "$TSET"

pushd ${IMGDIR} &> /dev/null

# generate data
for i in *.png; do
    PBM=${i%png}pbm
    TEXT=${i%png}txt
    convert "$i" "$PBM"
    pnmtoplainpnm $PBM > tmp
    ../../gen2svm/gen2svm "$TEXT" tmp >> ../"$TSET"
    rm ${PBM}
done

popd &> /dev/null

mv "${TSET}" ..
