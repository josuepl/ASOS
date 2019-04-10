#!/bin/sh
FILE=/tmp/archivo
if [ -r $FILE -a ! -w $FILE ]; then
  echo Fichero $FILE existe y no es modificable
else
  echo Fichero no encontrado o es modificable
fi
VAR1=3; VAR2=1;
if [ $(($VAR1)) -ne $(($VAR2)) ]; then
  echo Distintos
elif ls /; then
 :
fi


a=$1
echo $a
echo ${a}
b=""
echo $b
c=$(cat /etc/passwd | grep $a)
echo ${c}
if [ $c = $b ]; then
  echo 'No se encuentra el usuario'
else
    echo Funciona
  echo 'Sigue FUnc'
  echo "Menu:"
  echo "1) Opcion 1"
  echo "2) Opcion 2"
  echo "Opcion seleccionada: "
  read OPCION
  case $OPCION in
   1)
     echo "Opcion 1 seleccionada" ;;
   2)
     echo "Opcion 2 seleccionada" ;;
   *)
     echo "Opción errónea";
     echo $OPCION;;
 esac 
  
fi 
