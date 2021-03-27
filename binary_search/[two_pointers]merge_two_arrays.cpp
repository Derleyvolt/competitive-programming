#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

// juntando 2 arrays já ordenados e formando um terceiro array ordenado.
// O(len(a) + len(b))
// essa técnica é a mesma utilizada no algoritmo mergesort

vi merge(vi& a, vi& b) {
    vi ans(a.size() + b.size());
    int l, r, k;
    l = r = k = 0;
    while(l < a.size() and r < b.size()) {
        if(a[l] <= b[r]) {
            ans[k] = a[l];
            l++;
        } else {
            ans[k] = b[r];
            r++;
        }
        k++;
    }

    while(l < a.size()) {
        ans[k] = a[l];
        k++;
        l++;
    }

    while(r < b.size()) {
        ans[k] = b[r];
        k++;
        r++;
    }
    return ans;
}

int main() {
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    for(auto& k:a) cin >> k;
    for(auto& k:b) cin >> k;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vi ans = merge(a, b);
    for(auto a:ans) cout << a << " ";
    cout << endl;
}
