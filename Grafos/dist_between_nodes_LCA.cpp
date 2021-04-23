/*
    Se quisermos saber a distância entre dois nós numa árvore podemos escolher qualquer nó pra ser a raíz. Apesar do LCA ser afetado, a distância não é afetada, independente do nó raíz que
    escolhamos pra ser raíz.. é fácil provar isso:
    
    Minha prova:
    
    Primeiro sabemos que o LCA(u, v) pertence ao u, v-caminho. Prova: https://www.youtube.com/watch?v=tsounjNPeV8
    
    Segundo notemos que a distância entre 2 vértices de uma árvore é a distância do único caminho que há entre esses 2 vértices.
    
    Portanto, a distância entre u e v é dada pela distância do LCA ao vértice v + a distância do LCA ao vértice u ou seja:
    
    seja x o LCA(u, v).
    
    dist(x, v) + dist(x, u) = dist(u, v) .. como x está pertence ao u,v-caminho, a distância é constante em relação à raíz.
 
*/


#include <bits/stdc++.h>

using namespace std;

#define endl  '\n'
#define vi  vector<int>
#define ii  array<int, 2>
#define ll  long long
#define INF (int)1e9

const int maxn = 100, lg = 20;

vi adj[maxn];

int time_stamp[maxn][2], up[maxn][lg+1];

int timer, h[maxn];

void dfs(int s, int p, int a) {
    h[s] = a;
    time_stamp[s][0] = ++timer;
    up[s][0] = p;
    for(int i = 1; i <= lg; i++)
        up[s][i] = up[up[s][i-1]][i-1];
    for(int u : adj[s])
        if(u != p)
            dfs(u, s, a+1);
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
    for(int i = lg; i >= 0; i--)
        if(not is_ancestor(up[u][i], v))    
            u = up[u][i];
    return up[u][0];
}

int dist(int u, int v) {
    // h[u] + h[v] eu conto a distancia do root pro 
    // LCA(u, v) 2 vezes..
    return (h[u] + h[v]) - 2 * h[LCA(u, v)];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m; cin >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1, 0);
    cout << LCA(5, 7) << endl;
    cout << dist(8, 4) << endl;
    return 0;
}
