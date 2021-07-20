#include <bits/stdc++.h>

using namespace std;

#define ll  long long

const ll m = 1e9 + 7;

// algumas aplicações e melhorias em relação às colisões: https://cp-algorithms.com/string/string-hashing.html

ll hash_func(string str) {
    ll ans = 0, p = 1;
    for(auto c : str) {
        ans += (c - 'a' + 1) * p % m;
        p = p * 31;
    }

    return ans;
}

int main() {
    string s = "ratatuile";
    cout << hash_func(s) << endl;
    return 0;
}
