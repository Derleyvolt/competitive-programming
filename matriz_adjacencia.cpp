#include <bits/stdc++.h>

using namespace std; 

#define MAXN 1024

// como a matriz de adjacência consome muita memória,
// só é possível usarmos matriz_adj em casos onde o
// número de vértices é menor ou igual a 10 ao cubo ou um pouco maior que isso

int n; // geralmente n é o número de vértices
int m; // geralmente m é o número de arestas
int matrix_a[MAXN][MAXN]; // matriz "quadrada" onde cada linha representa um vértice e cada elemento dessa coluna representa as posições arestas desse vértice a outros vértices

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = m; i--;) {
        int u, v; cin >> u >> v;
        matrix_a[u][v] = 1; // caso seja direcionado adiciono 
        matrix_a[v][u] = 1; // os 2 vértices
    }
    // printando a matriz quadrada matrix_a
    for(int i = 1; i <= n; i++) {
        for(int k = 1; k <= n; k++)
            cout << matrix_a[i][k] << " ";
        cout << endl;
    }
    return 0;
}
