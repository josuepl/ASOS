#!/bin/sh
CONTADOR=0
until [ $CONTADOR -ge 3 ]; do
  echo El contador es $CONTADOR
  CONTADOR=$(($CONTADOR+1))
done