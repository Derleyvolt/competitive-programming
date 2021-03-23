#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

const int maxn = 1e5 + 10;

vi seg[4 * maxn];

vi arr(maxn);

// O(nlogn)
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

    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(seg[i]));
}

int query(int i, int tl, int tr, int l, int r) {
    if(tl > r or tr < l)
        return 0;
    if(l <= tl and r >= tr) {
        // .. geralmente roda uma busca binária aqui e etc..          
    }
    
    int m = (tl+tr)/2;
    
    int a = query(i * 2, tl, m, l, r);
    int b = query(i * 2 + 1, m+1, tr, l, r);
    
    return a + b;
}

void main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n-1);
}
