#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1000;

int p[maxn], s[maxn];

void init(int n) {
    for(int i = 0; i < n; i++) {
        p[i] = i;
        h[i] = 1;
    }
}

int root(int u) {
    if(u == p[u]) return u;
    return p[u] = root(p[u]); // path compression
}

void join(int u, int v) {
    u = root(u);
    v = root(v);
    if(u == v) return; // checa se dois vértices pertencem ao mesmo conjunto disjunto
    if(s[v] >= s[u]) swap(v, u);
    p[v] = u;
    s[u] += s[v];

/*
    o código acima faz exatamente a mesma coisa que o código abaixo, só é menor..

    u = root(u);
    v = root(v);
    
    if(s[v] >= s[u]) {
        p[u] = v;
        s[v] += s[u];
    }
    else {
        p[v] = u;
        s[u] += s[v];
    }
*/
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 7;
    init(n);
    return 0;
}
