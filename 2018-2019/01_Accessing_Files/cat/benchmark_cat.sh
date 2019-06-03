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

# First argument is input file (e.g. 10MB.dat)
# second argument is output file (e.g. cat_benchmarks.txt)
#  --created if doesn't exist, overwritten if exists
# third argument is the exponent floor 
# fourth optional argument is the exponent ceiling

# Example:
# ./benchmark_cat.sh 10MB.dat cat_benchmarks.txt 10 12
# will benchmark cat with
# input file: 10MB.dat
# buffer sizes: 2^10, 2^11, and 2^12 bytes
# and write the results to file cat_benchmarks.txt

# Another example without ranges:
# ./benchmark_cat.sh 10MB.dat cat_benchmarks.txt 6
# will only benchmark cat with a buffer of 2^6 bytes

if [ $# -lt 3 ]; then
    echo -e "Invalid argument count.\nUsage: $0" \
            "<input file> <output file>"         \
            "<exponent floor> <optional exponent ceiling>"
    exit 42
fi

case $3 in
    ''|*[!0-9]*)
        echo "Invalid exponent value '$3'."
        exit 43;;
esac

if [ -z "$4" ]; then
    lim=$3
else
    case $4 in
    ''|*[!0-9]*)
        echo "Invalid exponent value '$4'."
        exit 44;;
    esac

    lim=$4
fi

if [ "$3" -gt "$lim" ]; then
    echo "Exponent floor '$3' greater than exponent ceiling '$4'."
    exit 45
fi 

echo -e "cat.c compiled with optimization flags" \
        "-O2 and --march=native\n"               \
    > "$2"

echo "file size: $(stat -c%s "$1") bytes"

i=0
n=$((lim-$3+1))
tput civis
echo -en "$i/$n\r"
for exp in $(seq "$3" "$lim")
do
    pow=$(bc <<< "2^$exp")
    gcc -W -Wall -pedantic --std=c11      \
        -D USE_HEAP -D BUFFER_SIZE="$pow" \
        -O2 -march=native                 \
        cat.c -o cat

    echo -e "Blocks of $pow bytes" >> "$2"
    command time -p ./cat < "$1" > /dev/null 1 2>> "$2"
    echo  >> "$2"

    ((i++))
    echo -en "\r$i/$n"
done

truncate -s-1 "$2"
echo -e "\nCheck $2 for benchmarks."
tput cnorm
