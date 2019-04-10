#!/bin/sh
echo \$@=$@
echo \$*=$*
echo \$0=$0
echo \$1=$1
echo \$2=$2
echo Cambio parametros posicionales
set uno dos tres
echo \$1=$1
echo \$2=$2
echo Desplazo
shift
echo \$1=$1
echo \$2=$2
echo \$-=$-
echo \$#=$#
echo \$?=$?
firefox &
ps w
echo \$$=$$
echo \$!=$!
