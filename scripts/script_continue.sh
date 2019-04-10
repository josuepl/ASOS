#!/bin/sh
CONTADOR=0
for i in 1 2 3; do
  CONTADOR=$(($CONTADOR+$i))
  while [ $CONTADOR -lt 8 ]; do
    echo "Contador: $CONTADOR"
    CONTADOR=$(($CONTADOR+1))
    continue 2
    echo "Nunca llega a interpretarse"
  done
done