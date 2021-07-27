#include <bits/stdc++.h>

using namespace std;

#define endl  '\n'
#define vi  vector<int>
#define ll  long long

const ll m     = 1e9 + 7;
const int base = 31;
const int maxn = 1e6 + 10;

ll hs[maxn];
ll power[maxn];

void precompute_power() {
    power[0] = 1;
    for(int i = 1; i < maxn; i++) {
        power[i] = (power[i-1] * base) % m;
    }
}

void precompute_hash(string& s) {
    precompute_power();
    hs[0]= s[0]-'a'+1;
    for(int i = 1; i < s.size(); i++) {
        hs[i] = (hs[i-1] + (s[i]-'a'+1) * power[i]) % m;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    precompute_hash(s);

    int len = s.size();

    set<ll> cmp;
    
    // O(n^2logn)
  
    for(int i = 0; i < len; i++) {
        for(int j = i; j < len; j++) {
            ll h = i > 0 ? (hs[j]-hs[i-1]+m) % m : hs[j];
            cmp.insert(h * power[len-i] % m);
        }
    }

    cout << cmp.size() << endl;
    return 0;
}
