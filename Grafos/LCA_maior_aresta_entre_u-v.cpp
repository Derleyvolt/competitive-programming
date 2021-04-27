#include <bits/stdc++.h>

using namespace std;

#define endl  '\n'
#define vi  vector<int>
#define ii  array<int, 2>
#define ll  long long
#define INF (int)1e9

const int maxn = 1e5 + 10, lg = 20;

int time_stamp[maxn][2], up[maxn][lg+1], hup[maxn][lg+1];

int timer;

vector<ii> adj[maxn];

void dfs(int s, int p, int w) {
    time_stamp[s][0] = ++timer;
    up[s][0]  = p;
    hup[s][0] = w;
    for(int i = 1; i <= lg; i++) {
        up[s][i]  = up[up[s][i-1]][i-1];
        hup[s][i] = max(hup[s][i-1], hup[up[s][i-1]][i-1]);
    }

    for(auto [u, w] : adj[s])
        if(u != p)
            dfs(u, s, w);
    time_stamp[s][1] = ++timer;
}

bool is_anc(int u, int v) {
    return time_stamp[u][0] <= time_stamp[v][0] and
           time_stamp[u][1] >= time_stamp[v][1];
}

int LCA(int u, int v) {
    if(is_anc(u, v))
        return u;
    if(is_anc(v, u))
        return v;
    for(int i = lg; i >= 0; i--)
        if(not is_anc(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

int get_max(int u, int v, int lca) {
    if(lca == u)
        return 0;
    int ans = 0;
    for(int i = lg; i >= 0; i--) {
        if(not is_anc(up[u][i], v)) {
            // maior aresta de u até o vértice situado a
            // 2^i de distância dele
            ans = max(hup[u][i], ans);
            u = up[u][i];
        }
    }
    return max(ans, hup[u][0]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ...
    dfs(1, 1, -1);
    return 0;
}
