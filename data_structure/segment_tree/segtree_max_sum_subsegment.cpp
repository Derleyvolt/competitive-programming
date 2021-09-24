#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

pair<int, int> seg[4 * maxn];

int arr[maxn] = { 1, 2, 0, -1, 3, 4, 4, 6, 7, 2 };

void build(int i, int l, int r) {
    if(l == r) {
        seg[i].first  = arr[l];
        seg[i].second = 1;
        return;
    }

    int m = (l+r)/2;

    build(i*2, l, m);
    build(i*2+1, m+1, r);

    if(seg[i*2].first == seg[i*2+1].first) {
        seg[i].first  = seg[i*2].first;
        seg[i].second = seg[i*2].second + seg[i*2+1].second;
    } else {
        seg[i] = max(seg[i*2], seg[i*2+1]);
    }

}

pair<int, int> query(int i, int l, int r, int ql, int qr) {
    if(l > qr or r < ql) {
        return {};
    }

    if(l >= ql && r <= qr) {
        return seg[i];
    }

    int m = (l+r)/2;

    auto a = query(i*2, l, m, ql, qr);
    auto b = query(i*2+1, m+1, r, ql, qr);

    if(a.first == b.first) {
        seg[i].first  = a.first;
        seg[i].second = a.second + b.second;
    } else {
        seg[i] = max(a, b);
    }

    return seg[i];
}

int main() {
    build(1, 0, 9);

    auto ans = query(1, 0, 9, 2, 6);

    cout << ans.first << endl;
    cout << ans.second << endl;
    return 0;
}
