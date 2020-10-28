#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1001;

int parent[maxn], s[maxn];

void init(int n) {
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        s[i] = 1;
    }
}

int root(int u) {
    if(u == parent[u]) return u;
    return parent[u] = root(parent[u]); // path compression
}

void join(int u, int v) {
    u = root(u);
    v = root(v);
    if(u == v) return; // checa se dois vértices pertencem ao mesmo conjunto disjunto
    if(s[v] >= s[u]) swap(v, u);
    parent[v] = u;
    s[u] += s[v]; // perceba que só os representantes de cada conjunto disjunto é que vão guardar a informação do tamanho do conjunto.

/*
    o código acima faz exatamente a mesma coisa que o código abaixo, só é menor..

    u = root(u);
    v = root(v);
    if(u == v) return;
    if(s[v] >= s[u]) {
        parent[u] = v;
        s[v] += s[u];
    }
    else {
        parent[v] = u;
        s[u] += s[v];
    }
*/
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 7;
    init(n+1);
    join(1, 2);
    join(3, 6);
    join(6, 2);
    cout << root(1) << " " << root(6) << endl;
    cout << s[root(1)] << " " << s[root(5)] << endl;
    return 0;
}
