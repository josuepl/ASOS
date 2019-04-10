#!/bin/sh
VAR=1
echo $VAR
unset VAR
echo ${VAR:-k}
echo $VAR
FICH=fichero.c
FI=arch
echo ${FICH%.c}.o
echo ${FI%.aksjdka}.o
