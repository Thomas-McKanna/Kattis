#! /bin/bash

for i in {1..30}; do
    ../a.out < ${i}.in > ${i}.out
done