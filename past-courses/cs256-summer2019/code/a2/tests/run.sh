#!/bin/bash

prob="$1"

for f in tests/$prob.*.in; do
    echo "------------------"
    echo $f
    ./$prob < $f
    echo "------------------"
    echo
done;
