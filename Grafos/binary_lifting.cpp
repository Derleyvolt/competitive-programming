#include <bits/stdc++.h>

using namespace std;

#define vi  vector<int>

const int maxn = 100, lg = 20;

vi adj[maxn];

int time_stamp[maxn][2], up[maxn][lg+1];
int timer;

// nlogn pro preprocessamento..
void dfs(int s, int p) {
    time_stamp[s][0] = ++timer;
    up[s][0] = p;
    // obtendo os ancestrais que estão a potencias de 2 de distancia por recorrencia..
    for(int i = 1; i <= lg; i++)
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
    
    // dá pra provar isso usando o resultado https://pt.overleaf.com/read/fszrpzvsydsp
    // a prova do link pode se generalizada..
    
    // Quando saltamos 2^i caras pra cima significa que o 2^(i+1) (o i da iteração anterior) é um ancestral comum de u e v
    // e utilizando a prova acima (pra base 2) é possível mostrar que é sempre possível chegar
    // no vértice de altura 2^(i+1)-1
    for (int i = lg; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    dfs(root, root);
    timer = 0;
}

int main() {
    preprocess(1);
    return 0;
}
