#include <bits/stdc++.h>

using namespace std;

#define ll  long long

const ll m = 1e9 + 7;

// basea-se no pequeno teorema de fermat, portanto m precisa ser primo.

// https://cp-algorithms.com/algebra/module-inverse.html

ll expmod(ll b, ll e) {
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

int main() {
    cout << expmod(156156, m-2) << endl;
    return 0;
}
