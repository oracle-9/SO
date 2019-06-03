// Description  : University of Minho Operating Systems 2018/2019 worksheet 1
//                solved exercise 7.
//                Resolução do exercício 7 da ficha 1 de Sistemas Operativos
//                2018/2019 da Universidade do Minho.
//  Copyright   : © Oracle, 2019
//  License     : MIT
//  Maintainer  : oracle.uminho@gmail.com

#ifndef RNG_HPP
#define RNG_HPP

#include <random>

template <class T>
class RNG
{
   public:
    RNG() : rng(std::random_device()()) {}
    T operator()(const T min, const T max)
    {
        std::uniform_int_distribution<T> distr(min, max);
        return distr(rng);
    }

   private:
    std::mt19937 rng;
};

#endif
