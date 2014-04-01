#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Erreur, il faut un argument"
	exit 1
fi

echo $1 >> test

./main exemple.dat >> test
./main A/VRPA50.dat >> test
./main B/VRPB25.dat >> test
./main B/VRPB30.dat >> test
./main B/VRPB40.dat >> test
