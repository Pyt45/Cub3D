#!/bin/sh
if [ "$1" == "m" ]
then
    make
elif [ "$1" == "r" ]
then
    make re
elif [ "$1" == "f" ]
then
    make fclean
elif [ "$1" == "do" ]
then
    ./Cub3D map/map2.cub
else
    echo "have a nice day"
fi