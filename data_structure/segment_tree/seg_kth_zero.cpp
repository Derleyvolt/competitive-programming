#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int arr[maxn] = { 1, 0, 1, 0, 0, 3, 0, 4, 5 };

int seg[4 * maxn];

void build(int i, int l, int r) {
    if(l == r) {
        seg[i] = arr[l] == 0 ? 1 : 0;
        return;
    }

    int m = (l+r)/2;

    build(i*2, l, m);
    build(i*2+1, m+1, r);

    seg[i] = seg[i*2] + seg[i*2+1];
}

int query(int i, int l, int r, int ql, int qr) {
    if(l > qr or r < ql) {
        return 0;
    }

    if(ql >= l && qr <= r) {
        return seg[i];
    }

    int m = (l+r)/2;

    return query(i*2, l, m, ql, qr) + query(i*2+1, m+1, r, ql, qr);
}

pair<int, int> query(int i, int l, int r, int k) {
    if(l == r) {
        return {l, arr[l]};
    }
    
    int m = (l+r)/2;

    if(seg[i*2] >= k) {
        return query(i*2, l, m, k);
    } else {
        return query(i*2+1, m+1, r, k-seg[i*2]);
    }
}

int main() {
    build(1, 0, 8);
    auto ans = query(1, 0, 8, 4);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}
