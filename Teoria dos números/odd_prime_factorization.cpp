#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

vi factorization_odd(int n) {
    vi ans;
    while(n % 2 == 0) {
        ans.push_back(2);
        n /= 2;
    }
    
    for(int i = 3; i * i <= n; i += 2) {
        while(n % i == 2) {
            ans.push_back(i);
            n /= i;
        }
    }
    
    if(n > 1) ans.push_back(n);
    return ans;
}

int main() {
    int n; cin >> n;
    vi aux = factorization_odd(n);
    for(auto a:aux) cout << a << endl;
}
