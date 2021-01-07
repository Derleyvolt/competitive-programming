#include <bits/stdc++.h>

using namespace std;

#define ll long long


// O(sqrt(n))
vector<ll> divisors(ll n) {
    vector<ll> ans;
    for(ll i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            ans.push_back(i);
            if(n / i != i)
                ans.push_back(n/i);
        }
    }
    return ans;
}

int main() {
    int n; cin >> n;
    auto arr = divisors(n);
    for(auto a:arr) cout << a << endl;
    return 0;
}
