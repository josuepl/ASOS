#!/bin/sh
case $1 in
  archivo | file)
    echo Archivo ;;
  *.c)
    echo Fichero C ;;
  *)
    echo Error
    echo Pruebe otro ;;
esac 

echo \$* $*
echo \$0 $0
echo \$1 $1
echo \$2 $2
echo \$3 $3

