#include <bits/stdc++.h>

using namespace std; 

// O vetor da linha x é formado a partir desses:
// [1, -1, 0, 0]
// [0, 0, 1, -1]
// que são os offsets necessários para se movimentar num grid, horizontalmente e verticalmente.
// como cada movimento altera apenas um eixo por vez, ou seja, ora vou pra cima, ora vou pra baixo, esquerda ou direita, 
// então sempre haverá um 1 ou -1 junto com um 0 no par ordenado.. então, os primeiros 2 pares podem representar o cima e baixo,
// e os últimos 2 pares podem representar o direita e esquerda.

pair<int, int> mov[] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int matrix_a[10][10];

int main() {
    memset(matrix_a, -1, sizeof matrix_a);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < m; k++) {
            cin >> matrix_a[i][k];
        }
    }
    
    int l, r; l = r = 0;
    for(auto [x, y] : mov) {
        x += l; // posso alterar as variáveis, pois são cópias e não referências..
        y += r; 
        if(matrix_a[x][y] == -1 and x >= 0 and y >= 0 and x < n and x < m) {
            ...
        }
    }
    return 0;
}
