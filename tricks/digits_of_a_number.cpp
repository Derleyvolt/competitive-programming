#include <bits/stdc++.h>

using namespace std;

#define ll long long

// A prova disso é bastante simples :
// http://advancedmathyoungstudents.com/blog/2019/05/17/logarithms-as-digit-counters-in-any-base/

int main() {
    ll n; cin >> n
    cout << floor(log10(n)) + 1 << endl;
}
