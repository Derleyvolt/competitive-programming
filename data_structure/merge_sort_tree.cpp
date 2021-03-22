#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

const int maxn = 1e5 + 10;

vi seg[4 * maxn];

vi arr(maxn);

void build(int i, int l, int r) {
    if(l == r) {
        seg[i].push_back(arr[l]);
        return;
    }

    int m = (l+r)/2;

    build(i * 2, l, m);
    build(i * 2 + 1, m+1, r);

    vi& a = seg[i * 2];
    vi& b = seg[i * 2 + 1];

    merge(a.begin(), a.end(), b.begin(), b.end(), seg[i]);
}

void update(int i, int l, int r, int idx, int val) {
    if(l == r) {
        // é uma folha, é garantido ter no máx/min 1 elemento.
        seg[i][0] = val;
        return;
    }

    int m = (l+r)/2;

    if(idx <= m)
        update(i*2, l, m, idx, val);
    else
        update(i*2+1, m+1, r, idx, val);
    
    vi& a = seg[i * 2];
    vi& b = seg[i * 2 + 1];

    merge(a.begin(), a.end(), b.begin(), b.end(), seg[i]);
}

// void query(..) {...};
// a função de consulta é muito dependente do problema..

void main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n-1);
}
