#!/bin/sh
CONTADOR=0
while [ $CONTADOR -lt 3 ]; do
  echo "Contador: $CONTADOR"
  CONTADOR=$(($CONTADOR+1))
done