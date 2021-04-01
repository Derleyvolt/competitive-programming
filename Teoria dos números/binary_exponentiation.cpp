#include <bits/stdc++.h>

using namespace std;

#define m 1000000007
#define ll long long

ll exp(ll base, ll e) {
    ll ans = 1;
    while (e > 0) {
        if (e & 1)
            ans = ans * base;
        base = base * base;
        e >>= 1;
    }
    return ans;
}

// exponenciação binária modulada

ll mod_exp(ll base, ll e) {
    base %= m;
    ll ans = 1;
    while (e > 0) {
        if (e & 1)
            ans = ans * base % m;
        base = base * base % m; // garantir que m * m não cause overflow, pois a * a poderiam, potencialmente, causar overflow.
        e >>= 1;
    }
    return ans;
}

int main() {
    exp(8, 13);
}
