#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int arr[maxn] = {1, 2, 4, 1, -2, 6, -4, 3};
int seg[4*maxn];

void build(int i, int l, int r) {
    if(l==r) {
        seg[i] = arr[l];
        return;
    }

    int m = (l+r)/2;

    build(i*2, l, m);
    build(i*2+1, m+1, r);

    seg[i] = max(seg[i*2], seg[i*2+1]);
}

void update(int i, int l, int r, int idx, int val) {
    if(l==r) {
        arr[idx] = val;
        seg[i]   = val;
        return;
    }

    int m = (l+r)/2;

    if(idx <= m) {
        update(i*2, l, m, idx, val);
    } else {
        update(i*2+1, m+1, r, idx, val);
    }

    seg[i] = max(seg[i*2], seg[i*2+1]);
}

int query(int i, int l, int r, int val) {
    if(l == r) {
        return l;
    }

    int m = (l+r)/2;

    if(seg[i*2] >= val) {
        return query(i*2, l, m, val);
    } else {
        return query(i*2+1, m+1, r, val);
    }
}

int main() {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n-1);

    while(q--) {
        int a, b, c; cin >> a;
        if(a == 1) {
            cin >> b >> c;
            update(1, 0, n-1, b, c);
        } else {
            cin >> b;
            int aux = query(1, 0, n-1, b);
            if(arr[aux] >= b) {
                cout << aux << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
