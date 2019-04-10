#!/bin/bash
VAR=1
echo $VAR
unset VAR
echo ${VAR:=2} 
echo $VAR
FICH=/usr/bin/prueba
echo ${FICH##*/}

