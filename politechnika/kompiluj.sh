#!/bin/bash
BASEDIR=$(dirname "$0")
gcc -o main main.c funkcje.c magazyn.c -I $BASEDIR

echo "finished"


