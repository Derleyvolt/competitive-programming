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
    return parent[u] = root(parent[u]);
}

void join(int u, int v) {
    u = root(u);
    v = root(v);
    if(u == v) return;
    if(s[u] >= s[v]) swap(u, v);
    parent[u] = v;
    s[v] += s[u];
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    init(n);
    while(m--) {
        int a, b; cin >> a >> b;
        // basta subtrair 1 do número de elementos do conjunto a cada união dos conjuntos disjuntos.
        // A ideia é simples, inicialmente todos os subconjuntos disjuntos têm tamanho 1, então se eu unir qualquer elemento com qualquer outro
        // eu vou ter n-1 conjuntos disjuntos (componentes conexas).. basta verificar que estamos tratando sempre o novo conjunto formado
        // após a união como sendo um único elemento..
        if(root(a) != root(b)) // n -= root(a) != root(b);
          --n;
        join(a, b);
    }
    cout << n << endl;
    return 0;
}
