#!/bin/bash

# Description : University of Minho Operating Systems 2018/2019 worksheet 1
#               solved exercise 4.
#               Resolução do exercício 4 da ficha 1 de Sistemas Operativos
#               2018/2019 da Universidade do Minho.
# Copyright   : © Oracle, 2019
# License     : MIT
# Maintainer  : oracle.uminho@gmail.com
#

# If on an arch-based OS, requires package time installed
# (e.g. sudo pacman -S time)
# Also requires package bc (e.g. sudo pacman -S bc)

# First argument is cat source file (e.g. cat.c)
# second argument is input file (e.g. 10MB.dat)
# third argument is output file (e.g. cat_benchmarks.txt)
#  --created if doesn't exist, overwritten if exists
# fourth argument is the first exponent wall 
# fifth optional argument is the second exponent wall

# Example:
# ./benchmark_cat.sh cat.c 10MB.dat cat_benchmarks.txt 10 12
# will benchmark cat with
# input file: 10MB.dat
# buffer sizes: 2^10, 2^11, and 2^12 bytes
# and redirect time output to file cat_benchmarks.txt

# Another example without ranges:
# ./benchmark_cat.sh cat.c 10MB.dat cat_benchmarks.txt 6
# will only benchmark cat with a buffer of 2^6 bytes

[[ $# -lt 4 ]] && exit 1

echo "$1 compiled with optimization flags" \
        "-O2 and --march=native\n"         \
    > $3

echo "file size: $(stat -c%s $2) bytes"

[[ -z "$5" ]] && lim=$4 || lim=$5

i=0
n=$(($lim-$4+1))
tput civis
echo -en "$i/$n\r"
for exp in `seq $4 $lim`
do
    pow=$(bc <<< "2^$exp")
    gcc -W -Wall -pedantic --std=c11    \
        -D USE_HEAP -D BUFFER_SIZE=$pow \
        -O2 -march=native               \
        $1 -o cat
    echo -e "Blocks of $pow bytes" >> $3
    { command time -p ./cat < $2 > /dev/null 1; } 2>> $3
    echo  >> $3
    ((i++))
    echo -en "\r$i/$n"
done

truncate -s-1 $3
echo -e "\nCheck $3 for benchmarks."
tput cnorm
