#include <bits/stdc++.h>

using namespace std; 

const int MAXN = 100;

int n;
vector<int> adj[MAXN], dist;

vector<int> bfs(int s, int p) {
    queue<int> q; q.push(s);
    dist[s] = 0; // considerando a primeira camada como tendo distância 1
    while(not q.empty()) {
        int r = q.front(); q.pop();
        for(auto a:adj[r]) {
            if(dist[a] == -1) {
                q.push(a);
                dist[a] = dist[r]+1;
            }
        }
    }
    return arr;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int m; cin >> n >> m;
    dist = vector<int>(n+1,-1);
    for(int i = m; i--;) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    return 0;
}
