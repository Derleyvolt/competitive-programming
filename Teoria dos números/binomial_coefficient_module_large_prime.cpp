#include <bits/stdc++.h>

using namespace std;

#define ll  long long

const ll m = 1e9 + 7;

const int maxn = 1e5 + 10;

ll fact[maxn];

// precomputando os fatoriais modulo 1e9+7
void pp() {
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) {
        fact[i] = (fact[i-1] * i) % m;
    }
}

int exp_mod(ll b, ll e) {
    ll ans = 1;
    while(e > 0) {
        if(e&1) {
            ans = (ans * b) % m;
        }

        b = (b * b) % m;
        e = e >> 1;
    }
    return ans;
}

int inv_mod(int n) {
    return exp_mod(n, m-2);
}

// como os fatorais são obtidos em O(1), o custo aqui é só pra calcular o inverso modular, ou seja, O(logm).
int C(int n, int k) {
    return (fact[n] * inv_mod((fact[k] * fact[n-k]) % m)) % m;
}

int main() {
    pp();
    cout << C(19, 7) << endl;
    return 0;
}
