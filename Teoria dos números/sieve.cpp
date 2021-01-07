#include <bits/stdc++.h>

using namespace std; 

// O upper bound para a complexidade do algortitmo é O(nlogn)

const int maxn = 1e6 + 10;

bitset<maxn> table;

// mostra todos os primos de 1 até n
void sieve(int n) {
    for(int i = 2; i <= n; i++) {
        if(table[i]) continue;
        for(int k = i * 2; k <= n; k += i)
            table[k] = 1;
    }
}

int main() {
    sieve(100);
    for(int i = 2; i <= 100; i++) {
        if(table[i] == 0)
            cout << i << endl;
    }
    return 0;
}
