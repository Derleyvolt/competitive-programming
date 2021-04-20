// https://medium.com/@kumarrocky436/dfs-time-stamp-on-nodes-da76a51a50cb
// essa técnica é utilizada em vários algoritmos relacionados a grafos..


#include <bits/stdc++.h>

using namespace std;

#define vi  vector<int>

const int maxn = 1e5 + 10;

int chegada[maxn], saida[maxn], visited[maxn];

vi G[maxn];

int timer = 0;

void dfs(int s) {
    chegada[s] = ++timer;
    visited[s] = 1;
    for(int u : G[s]) {
        if(visited[u] != 1)
            dfs(u);
    }
    saida[s] = ++timer;
}

int main() {
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1);
    for(int i = 1; i <= n; i++)
        cout << i << " chegada: " << chegada[i] << " saida: " << saida[i] << endl;
    return 0;
}
