#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1010;

int parent[maxn];

int n, m;

void init(int n) {
    for(int i = 0; i < n; i++)
        parent[i] = i;
}

int root(int u) {
    if(u==parent[u]) return u;
    return parent[u] = root(parent[u]);
}

void join(int u, int v) {
    u = root(u);
    v = root(v);
    parent[v] = u;
}

array<int, 3> arr[maxn];

int mst() {
    int ans = 0;

    sort(arr, arr + m, [](auto a, auto b) {
        return a[2] > b[2];
    });

    for(int i = 0, j = 0; i < m and j < n-1; i++) {
        auto [u, v, w] = arr[i];

        if(root(u) != root(v)) {
            j++;
            ans += w;
            join(u, v);
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    return 0;
}
