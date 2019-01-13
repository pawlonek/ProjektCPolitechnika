#!/bin/bash
BASEDIR=$(dirname "$0")
gcc -o main main.c funkcje.c -I $BASEDIR
clear
echo "finished"


