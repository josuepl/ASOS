#!/bin/sh
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
