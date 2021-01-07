#include <bits/stdc++.h>

using namespace std;

#define ll long long

// O(sqrt(n))

bool is_prime(ll n) {
    if(n < 2)
        return false;
    if(n == 2)
        return true;
    for(ll i = 3; i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main() {
    ll n; cin >> n;
    cout << boolalpha << is_prime(n) << endl;
}
