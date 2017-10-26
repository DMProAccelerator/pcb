#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

if [ -z $1 ]; then
	PROJ="."
else
	PROJ="$1"
fi

#cd "$DIR/$PROJ" || exit 1
(make clean && make) || exit 1

cd $DIR
./flash.sh $DIR/$PROJ/bin/$PROJ.bin
