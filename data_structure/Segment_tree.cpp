#include <bits/stdc++.h>

using namespace std;

int a[MAX]; // array original
int seg[MAX];

void build(int u, int l, int r) {// u é o indice do nó n árvore, e armzzena o segmento A[i..j]
    if (l == r) {
        tsum[u] = a[l];
        return;
    }

    int md = (l + r) / 2;

    build(u * 2, l, md); // controi sub arvore esquerda
    build(u * 2 + 1, md + 1, r); // controi sub arvore direita
    tsum[u] = comb(tsum[u * 2], tsum[u * 2 + 1]);
}

void update(int u, int l, int r, int idx, int val) {
    if (l == r) {
        tsum[u] = val;
        return;
    }

    int m = (l + r) / 2;

    if (idx <= m)
        update(esq(u), l, m, idx, val);
    else
        update(dir(u), m + 1, r, idx, val);

    tsum[u] = comb(tsum[u * 2], tsum[u * 2 + 1]);
}

int query(int u, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl and r == tr)
        return tsum[u];

    int m = (tl + tr) / 2;
    int a = query(u * 2, tl, m, l, min(r, m));
    int b = query(u * 2 + 1, m + 1, tr, max(l, m + 1), r);
    return a + b;
}

int l, r, idx, val, op;

int main() {
    long long aa = -5;
    cout << aa << endl;

    return 0;

    freopen("in.txt", "r", stdin);
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    build(1, 1, n);

    while (cin >> op) {
        if (op == 1) {
            cin >> idx >> val;
            update(1, 1, n, idx, val);
            cout << "Atualizou" << endl;
        }
        if (op == 2) {
            cin >> l >> r;
            cout << "soma: " << query(1, 1, n, l, r) << endl;
        }
    }

    return 0;
}
