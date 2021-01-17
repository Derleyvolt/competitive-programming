#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> trial_division2(ll n) {
    vector<ll> ans;
    while (n % 2 == 0) {
        ans.push_back(2);
        n /= 2;
    }
    for (ll d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            ans.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        ans.push_back(n);
    return ans;
}

int main() {
    
}
