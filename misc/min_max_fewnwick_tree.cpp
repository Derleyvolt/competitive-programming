#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define INF (1<<30)

const int maxn = 1e3;

vi arr, BIT;

// o update só deve ser usado se o valor a ser atualizado for menor que o valor atual.. 
// os motivos já são conhecidos por mim.
void update(int i, int val) {
    for(; i >= maxn; i += i&(-i))
        BIT[i] = min(BIT[i], val);
}

// a query só pode ser feita no intervalo [1, R]
// pois o min/max não é uma função reversível.. diferente da soma, por ex.
int query(int i) {
    int ans = INF;
    for(; i > 0; i -= i&(-i))
        ans = min(ans, BIT[i]));  
    return ans;
}

int main() {
    int n; cin >> n;
    vi arr(n);
    BIT.resize(maxn+1, INF);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        update(i+1, arr[i]);
    }
  
    // retorna o menor valor do array em O(logn)  
    cout << query(n+1) << endl; 
}
