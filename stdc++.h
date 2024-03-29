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

// MACRO E FUNÇÕES QUE AUXILIAM A DEBUGAR

#define NAME(v) #v

std::mt19937 gen(time(NULL));

int RNG(int min, int max) {
    std::uniform_int_distribution<int> generator(min, max);
    return generator(gen);
}

template<class T>
void db(T var, const char* name = NAME(var)) {
    std::cout << name << " -> " << var << std::endl;
}

template<class T>
void dbvet(T& container, const char* name = NAME(container)) {
    std::cout << name << " -> [";
    int len = container.size();
    for (int i = 0; i < len; i++) {
        if(i < len-1) 
            std::cout << container[i] << ", ";
        else
            std::cout << container[i] << "]" << std::endl;
    }
}

template<class T>
void dbmap(T& mp, const char* name = NAME(mp)) {
    std::cout << name << " -> ["; bool fl = 0;
    for (auto [a, b] : mp) {
        if (name == NULL)
            std::cout << ", ";
        std::cout << "[" << a << ", " << b << "]";
        name = NULL;
    }
    std::cout << "]" << std::endl;
}

// mat não vem como referência pq a função deve aceitar também
// uma matriz de int, ou char, por ex..
template<class T>
void dbmat(T mat, int n, int m, bool sep = false, const char* name = NAME(mat)) {
    std::cout << name << " -->" << std::endl;
    std::string s = sep ? " " : "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << mat[i][j] << s;
        }
        std::cout << std::endl;
    }
}

#define dbmat(mat, n, m, sep) dbmat(mat, n, m, sep, NAME(mat))
#define dbmap(arr) dbmap(arr, NAME(arr))
#define db(var) db(var, NAME(var))
#define dbvet(cont) dbvet(cont, NAME(cont))
