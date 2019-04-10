#!/bin/sh
VAR=1
VAR=$VAR+1
echo $VAR
RES1=$(($VAR))+1
echo $RES1
VAR=1
RES2=$((VAR + 1)) #VAR no necesita $ 
echo $RES2
VARb=b
echo $(($VARb+1))
