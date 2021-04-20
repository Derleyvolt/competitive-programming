// Este é o arquivo stdc++.h do compilador gcc.. eu tirei vários files desnecessários para a vida de um programador competitivo
// portanto há aqui somente o necessário.

// C:\MinGW\lib\gcc\mingw32\9.2.0\include\c++\mingw32\bits

#include <assert.h>

// C++
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <array>
#include <chrono>
#include <forward_list>
#include <initializer_list>
#include <random>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

// Macros e funções definidas por mim..

std::mt19937 gen(time(NULL));

int RNG(int min, int max) {
    std::uniform_int_distribution<int> generator(min, max);
    return generator(gen);
}

void db(const char* name, int val) {
    std::cout << name << " -> " << val << std::endl;
}

void db(int val, const char* name) {
    std::cout << name << " -> " << val << std::endl;
}

// pode ser passado qualquer container que tenha begin e end como membros e que tenha 
// um tipo aceito pelo <<operator do cout como argumento.
template<class vet>
void db(vet arr, const char* name) {
    std::cout << name << " -> [ ";
    for(auto a : arr) std::cout << a << " ";
    std::cout << "]" << std::endl;
}

#define NAME(v) #v
#define db(arg) db(arg, NAME(arg))


