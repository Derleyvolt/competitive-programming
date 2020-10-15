#include <bits/stdc++.h>

using namespace std; 

const int MAXN = 1000;

int n;
vector<int> adj[MAXN];
vector<bool> vis;

void bfs(int s) {
    queue<int> q; q.push(s);
    vis = vector<bool>(n+1);
    vis[s] = 1;
    while(not q.empty()) {
        int r = q.front(); q.pop();
        for(auto a:adj[r]) {
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
}
