#include <bits/stdc++.h>

using namespace std;

#define m 1000000007
#define ll long long

ll exp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

// exponenciação binária modulada

ll mod_exp(ll a, ll b) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m; // garantir que m * m não cause overflow, pois a * a poderiam, potencialmente, causar overflow.
        b >>= 1;
    }
    return res;
}

int main() {
    binpow(8, 13);
}
