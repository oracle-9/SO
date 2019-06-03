#!/bin/bash

# Description : University of Minho Operating Systems 2018/2019 worksheet 1
#               solved exercise 7.
#               Resolução do exercício 7 da ficha 1 de Sistemas Operativos
#               2018/2019 da Universidade do Minho.
# Copyright   : © Oracle, 2019
# License     : MIT
# Maintainer  : oracle.uminho@gmail.com

# First argument is flag (-a for adding, -u for updating)
# second argument is the person's name
# third argument is the person's age 
# fourth argument is the database file

# Example (-a):
# ./person.sh -a "Sardão da Noite" 1 people.txt
# will add the entry "Sardão da Noite 1" to the file people.txt

# Example (-u):
# ./person.sh -u "Gigolo Verde Alface" 200 people.txt
# will change the first occurrence of the person "Gigolo Verde Alface"'s
# age to 200, if that person exists in the file

if [ "$#" -lt 4 ]; then
    echo -e "Invalid argument count.\nUsage $0" \
            "-a|-u <person name> <person age> <database file>"
    exit 42
fi

case $1 in
    '-a')
        echo "$2 $3" >> "$4";;
    '-u')
        sed -i 's/'"$2"' .*$/'"$2 $3"'/' "$4";;
    *)
        echo -e "Unrecognized flag $1."
        exit 43
esac
