#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int seg[4 * maxn], arr[maxn];

// O(n)
void build(int i, int l, int r) {
    if (l == r) {
        seg[u] = arr[l];
        return;
    }

    int m = (l + r) / 2;

    build(i * 2, l, m);
    build(i * 2 + 1, m + 1, r);
    
    seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

// O(logn)
void update(int i, int l, int r, int idx, int val) {
    if (l == r) {
        seg[i] = val;
        return;
    }

    int m = (l + r) / 2;

    if (idx <= m)
        update(i * 2, l, m, idx, val);
    else
        update(i * 2 + 1, m + 1, r, idx, val);

    seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

// O(logn)
int query(int i, int tl, int tr, int l, int r) {
    // fora dos limites da consulta
    if (tl > r or tr < l)
        return 0;
    // o intervalo de busca está dentro dos limite da consulta
    if (l <= tl and r >= tr)
        return seg[i];

    int m = (tl + tr) / 2;
    
    int a = query(i * 2, tl, m, l, r);
    int b = query(i * 2 + 1, m + 1, tr, l, r);
    return a + b;
}

/*

uma outra versão da query function..

int query(int i, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl and r == tr)
        return seg[i];

    int m = (tl + tr) / 2;
    
    int a = query(i * 2, tl, m, l, min(r, m));
    int b = query(i * 2 + 1, m + 1, tr, max(l, m+1), r);
    return a + b;
}
*/

int main() {
    int n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n-1);
    return 0;
}
