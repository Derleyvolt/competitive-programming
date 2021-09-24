#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int arr[maxn];

pair<int, int> seg[4*maxn];

void build(int i, int l, int r) {
    if(l == r) {
        seg[i].first  = arr[l];
        seg[i].second = l;
        return;
    }

    int m = (l+r)/2;

    build(i*2, l, m);
    build(i*2+1, m+1, r);

    seg[i].first  = seg[i*2].first + seg[i*2+1].first;
    seg[i].second = -1;
}

void update(int i, int l, int r, int idx, int val) {
    if(l == r) {
        arr[idx]      = val;
        seg[i].first  = val;
        seg[i].second = idx;
        return;
    }

    int m = (l+r)/2;

    if(idx <= m) {
        update(i*2, l, m, idx, val);
    } else {
        update(i*2+1, m+1, r, idx, val);
    }

    seg[i].first  = seg[i*2].first + seg[i*2+1].first;
    seg[i].second = -1;
}

int query(int i, int l, int r, int k) {
    if(l == r) {
        return seg[i].second;
    }

    int m = (l+r)/2;

    if(seg[i*2].first <= k) {
        return query(i*2+1, m+1, r, k-seg[i*2].first);
    } else {
        return query(i*2, l, m, k);
    }
}

int main() {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n-1);
    while(q--) {
        int a, b; cin >> a >> b;
        if(a == 1) {
            update(1, 0, n-1, b, 1^arr[b]);
        } else {
            cout << query(1, 0, n-1, b) << endl;
        }
    }
    return 0;
}
