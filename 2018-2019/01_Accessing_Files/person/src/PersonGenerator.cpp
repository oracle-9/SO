// Description  : University of Minho Operating Systems 2018/2019 worksheet 1
//                solved exercise 7.
//                Resolução do exercício 7 da ficha 1 de Sistemas Operativos
//                2018/2019 da Universidade do Minho.
//  Copyright   : © Oracle, 2019
//  License     : MIT
//  Maintainer  : oracle.uminho@gmail.com

#include "RNG.hpp"

#include <algorithm>
#include <cctype>
#include <cerrno>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <thread>
#include <unordered_set>

#define MAX_PERSON_AGE 123

using namespace std;

enum ErrorCodes : int
{
    ERR_INV_ARGC           = 42,
    ERR_INV_NAME_COUNT     = 43,
    ERR_EMPTY_DB           = 44,
    ERR_INSUF_COMBINATIONS = 45
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);

    if (argc < 5)
    {
        cerr << "Invalid argument count.\n"
                "Usage: " << argv[0] << "<first names file> <last names file> "
                "<ammount of names> <output file>"
             << endl;
        return ERR_INV_ARGC;
    }

    for (const char *i = argv[3]; *i; ++i)
    {
        if (!isdigit(*i))
        {
            cerr << "Invalid ammount of names." << endl;
            return ERR_INV_NAME_COUNT;
        }
    }

    ifstream fst_names_db(argv[1]);
    if (fst_names_db.fail())
    {
        cerr << strerror(errno) << ": " << argv[1] << endl;
        return errno;
    }

    ifstream lst_names_db(argv[2]);
    if (lst_names_db.fail())
    {
        cerr << strerror(errno) << ": " << argv[2] << endl;
        return errno;
    }

    const auto count_ifstream_lines = [](auto &ifstream) {
        const auto nlines = count(istreambuf_iterator<char>(ifstream),
                                  istreambuf_iterator<char>(),
                                  '\n');
        ifstream.seekg(0);
        return nlines;
    };

    const auto fst_names_count = count_ifstream_lines(fst_names_db);
    if (!fst_names_count)
    {
        cerr << "Empty file " << argv[1] << '.' << endl;
        return ERR_EMPTY_DB;
    }

    const auto lst_names_count = count_ifstream_lines(lst_names_db);
    if (!lst_names_count)
    {
        cerr << "Empty file " << argv[2] << '.' << endl;
        return ERR_EMPTY_DB;
    }

    const auto requested_count = stoull(argv[3]);

    do
    {
        const uintmax_t ncombinations =
            static_cast<uintmax_t>(fst_names_count) *
            static_cast<uintmax_t>(lst_names_count);

        if (ncombinations < static_cast<uintmax_t>(requested_count))
        {
            cerr << "Insufficient name combinations for requested name count."
                    "\nPossible combinations: " << ncombinations
                 << "\nRequested name count: "  << requested_count
                 << endl;
            return ERR_INSUF_COMBINATIONS;
        }
    } while (0);

    vector<string> fst_names;
    fst_names.reserve(fst_names_count);

    vector<string> lst_names;
    lst_names.reserve(lst_names_count);

    const auto ifstream_to_vec_func = [](auto &in, auto &out)
    {
        return [&]()
        {
            string tmp;
            while (in >> tmp)
            {
                out.push_back(move(tmp));
            }
        };
    };

    thread read_fst_names_thrd(ifstream_to_vec_func(fst_names_db, fst_names));
    thread read_lst_names_thrd(ifstream_to_vec_func(lst_names_db, lst_names));

    read_fst_names_thrd.join();
    read_lst_names_thrd.join();

    unordered_set<string> full_names;
    full_names.reserve(requested_count);

    RNG<size_t> rng;

    while (full_names.size() < requested_count) {
        full_names.emplace(fst_names[rng(0, fst_names.size() - 1)] +
                           ' '                                     +
                           lst_names[rng(0, lst_names.size() - 1)]);
    }

    ofstream out(argv[4]);
    for (const auto &i : full_names)
    {
        out << i + ' ' + to_string(rng(0, MAX_PERSON_AGE)) + '\n';
    }
}
