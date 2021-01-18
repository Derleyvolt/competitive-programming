#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

const int maxn = 3 * 1e7;

bitset<maxn> table;
vi primes;

void sieve() {
    for(int i = 2; i < maxn; i++) {
        if(table[i]) continue;
        primes.push_back(i);
        for(int j = i * 2; j < maxn; j += i)
            table[j] = 1;
    }
}

vi factorization(int n) {
    vi ans;
    for(auto num : primes) {
        if(num * num > n)
            break;
        while(n % num == 0) {
            ans.push_back(num);
            n /= num;
        }
    }
    
    if(n > 1) ans.push_back(n);
    return ans;
}

int main() {
    sieve();
    vi ans = factorization(151644496);
    for(auto a:ans) cout << a << endl;
}
