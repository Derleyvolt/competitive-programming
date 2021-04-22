#include <bits/stdc++.h>

using namespace std;

#define vi  vector<int>

const int maxn = 100;
const int log  = 20;

vi adj[maxn];

int time_stamp[maxn][2], up[maxn][log+1];
int timer;

// nlogn pro preprocessamento..
void dfs(int s, int p) {
    time_stamp[s][0] = ++timer;
    up[s][0] = p;
    // obtendo os ancestrais que estão a potencias de 2 de distancia por recorrencia..
    for(int i = 1; i <= log; i++)
        up[s][i] = up[up[s][i-1]][i-1];
    for(int u : G[s]) {
        if(u != p)
            dfs(u, s);
    }
    time_stamp[s][1] = ++timer;
}

bool is_ancestor(int u, int v) {
    return time_stamp[u][0] <= time_stamp[v][0] and 
           time_stamp[u][1] >= time_stamp[v][1];
}

int LCA(int u, int v) {
    if(is_ancestor(u, v))
        return u;
    if(is_ancestor(v, u))
        return v;
    for (int i = log; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int main() {
    int root = 1;
    dfs(root, root);
    return 0;
}
