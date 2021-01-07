#include <bits/stdc++.h>

using namespace std; 

// O upper bound para a complexidade do algortitmo é O(nlogn)

const int maxn = 1e6 + 10;

bitset<maxn> table;
vector<int>  primes;

// mostra todos os primos de 1 até n
void sieve(int n) {
    for(int i = 2; i <= n; i++) {
        if(table[i]) continue;
        primes.push_back(i);
        for(int j = i * 2; j <= n; j += i)
            table[j] = 1;
    }
}

int main() {
    sieve(100);
    for(auto a:primes) cout << a << endl;
    return 0;
}

