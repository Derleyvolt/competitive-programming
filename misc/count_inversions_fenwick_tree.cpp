#include <bits/stdc++.h>

using namespace std;

#define vi  vector<int>
#define ii  array<int, 2>
#define ll  long long
#define INF (1<<30)

const int maxn = 1e7 + 10;

int BIT[maxn], len;

void update(int i, int val) {
    for(++i;i<=len; i += i&(-i))
        BIT[i] += val;
}

int query(int i) {
    int ans = 0;
    for(++i;i>0; i-=i&(-i))
        ans += BIT[i];
    return ans;
}

// os valores do array serão usados como entrada pra BIT, então a BIT precisa ter capacidade pro maior valor que o array pode conter..

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vi arr(n);
    for(auto& a:arr) {
        cin >> a;
        len = max(len, a);
    }

    BIT.resize(len+10);
    
    int ans = 0;
    for(int i = n-1; i >= 0; i--) {
        ans += query(arr[i]-1); // olho quantos caras vieram antes de arr[i]
        update(arr[i], 1); // atualizo o arr[i]
    }

    cout << ans << '\n';
    return 0;
}
