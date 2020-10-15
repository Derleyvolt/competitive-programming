#include <bits/stdc++.h>

using namespace std; 

const int MAXN = 1010;

int n;
vector<int> adj[MAXN];
vector<bool> vis;

void bfs(int s) {
    queue<int> q; q.push(s);
    vis[s] = 1;
    while(not q.empty()) {
        int r = q.front(); q.pop();
        for(int a:adj[r]) {
            if(vis[a] == 0) {
                q.push(a);
                vis[a] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int m; cin >> n >> m;
    // inicializa o vetor de visitados
    vis.resize(n+1);
    while(m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int components = 0;
    // 1-indexed
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            bfs(i);
            components++;
        }
    }
    cout << counter << endl;
}
