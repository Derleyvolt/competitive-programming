#include <bits/stdc++.h>

using namespace std;

// o problema teste do codeforce pra esse assunto tem casos mt fracos, o código passou lá mas dps eu testo melhor..

#define ll long long
const int maxn = 1e5 + 10;

struct dt {
    ll pref    = 0, suf = 0;
    ll sum     = 0;
    ll max_seg = 0;
};

ll arr[maxn];
dt seg[4 * maxn];

void build(int i, int l, int r) {
    if(l == r) {
        seg[i].sum      = arr[l];
        seg[i].max_seg  = max(arr[l], 0LL);
        seg[i].pref     = max(arr[l], 0LL);
        seg[i].suf      = max(arr[l], 0LL);
        return;
    }

    int m = (l+r)/2;

    build(2*i, l, m);
    build(2*i+1, m+1, r);

    // calcuando meu maior prefixo e sufixo em função dos meus 2 segmentos, cujo os dados já possuo.
    seg[i].pref = max(seg[i*2].pref, seg[i*2].sum + seg[i*2+1].pref);
    seg[i].suf  = max(seg[i*2+1].suf, seg[i*2+1].sum + seg[i*2].suf);
    seg[i].sum  = seg[i*2].sum + seg[i*2+1].sum;

    seg[i].max_seg = max({seg[i*2].suf+seg[i*2+1].pref, seg[i*2].max_seg, seg[i*2+1].max_seg});
}

void update(int i, int l, int r, int idx, int val) {
    if(l==r) {
        arr[idx]        = val;
        seg[i].sum      = arr[idx];
        seg[i].max_seg  = max(arr[idx], 0LL);
        seg[i].pref     = max(arr[idx], 0LL);
        seg[i].suf      = max(arr[idx], 0LL);
        return;
    }

    int m = (l+r)/2;

    if(idx <= m) {
        update(i*2, l, m, idx, val);
    } else {
        update(i*2+1, m+1, r, idx, val);
    }

    seg[i].pref = max(seg[i*2].pref, seg[i*2].sum + seg[i*2+1].pref);
    seg[i].suf  = max(seg[i*2+1].suf, seg[i*2+1].sum + seg[i*2].suf);
    seg[i].sum  = seg[i*2].sum + seg[i*2+1].sum;

    seg[i].max_seg = max({seg[i*2].suf+seg[i*2+1].pref, seg[i*2].max_seg, seg[i*2+1].max_seg});
}

dt query(int i, int l, int r, int ql, int qr) {
    if(ql > r or qr < l) {
        return {};
    }

    if(l >= ql && r <= qr) {
        return seg[i];
    }

    int m = (l+r)/2;

    dt a = query(i*2, l, m, ql, qr);
    dt b = query(i*2+1, m+1, r, ql, qr);

    dt ans;

    ans.pref    = max(a.pref, a.sum + b.pref);
    ans.suf     = max(b.pref, b.sum + a.pref);
    ans.sum     = a.sum + b.sum;
    ans.max_seg = max({a.suf+b.pref, a.max_seg, b.max_seg});

    return ans;
}

int main() {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n-1);

    while(q--) {
        cout << query(1, 0, n-1, 0, n-1).max_seg << endl;
        int a, b; cin >> a >> b;
        update(1, 0, n-1, a, b);
    }

    cout << query(1, 0, n-1, 0, n-1).max_seg << endl;

    return 0;
}
