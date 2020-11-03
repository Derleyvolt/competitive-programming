#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1010;

int parent[maxn];

int n, m;

void init(int n) {
    for(int i = 0; i < n; i++)
        parent[i] = i;
}

int root(int u) {
    if(u==parent[u]) return u;
    return parent[u] = root(parent[u]);
}

void join(int u, int v) {
    u = root(u);
    v = root(v);
    parent[v] = u;
}

array<int, 3> arr[maxn]; // u, v e w

int mst() {
    int ans = 0;

    sort(arr, arr + m); // ordenada as arestas em função dos pesos

/*   
    considere v como sendo o número de vértices.

    o j é usado numa otimização que verifica se o número de arestas encontradas tem tamanho v-1.  
    essa otimização só funciona em grafos com 1 componente.. mas não há problemas em usar em grafos com várias componentes conexas,
    a otimização não vai funcionar mas não vai atrapalhar.
    
    como o número exato de arestas pertencentes a (minimum) spanning tree é v-1, ele para quando o número de arestas obtidas for esse.
    
    for(int i = 0, j = 0; i < m and j < n-1; i++) {
        auto [u, v, w] = arr[i];

        if(root(u) != root(v)) {
            j++;
            ans += w;
            join(u, v);
        }
    }
*/  
    for(int i = 0; i < m; i++) {
        auto [u, v, w] = arr[i];

        if(root(u) != root(v)) {
            ans += w;
            join(u, v);
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    return 0;
}
