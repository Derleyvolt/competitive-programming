#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;

vector<int> adj[maxn];
int dist[maxn];

int dfs(int v) {
    int sum = 1;
    dist[v] = 1;
    for(auto a:adj[v]) {
        if(dist[a] == -1)
            sum += dfs(a);
  	}
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    memset(dist, -1, sizeof(dist));
    while(m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << dfs(1) << endl;
    return 0;
}
