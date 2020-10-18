#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> matrix_a;
vector<vector<int>> matrix_b;

int main() {
    freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;

    matrix_a.resize(n); // a matriz inicial tem as dimensões do input
    matrix_b.resize(m); // a matriz transposta da inicial tem dimensões opostas

    for (auto& a : matrix_a) a.resize(m); // as linhas aqui possuem m elementos
    for (auto& b : matrix_b) b.resize(n); // as linhas aqui possuem n elementos

    // as colunas de matrix_b são ordenamente iguais às linhas de matrix_a

    // em função de como a matriz transposta é matematicamente obtida, a diagonal principal de ambas as matrizes tem os mesmos elementos.

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> matrix_a[i][k];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++)
            cout << matrix_a[i][k] << "  ";
        cout << endl;
    }

    cout << endl;
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            // a matriz tranposta é criada aqui.. É bem simples, enquanto percorremos a linha da matriz original, percorremos também
            // a coluna correspondente da matriz transposta.
            // então, por ex, todo elemento que estiver na primeira linha, será transportado à primeira coluna, e todo elemento da segunda 
            // coluna será transportado à segunda linha, da matriz transposta. Então o elemento a[1][2] será transportado 
            // pra a[2][1], primeira coluna e segunda linha..
            matrix_b[k][i] = matrix_a[i][k]; // aqui, enquanto percorre a linha i da matriz original, percorre a coluna i, da matriz tranposta
                                             // então é de suma importante que as colunas da matriz tranposta tenham o mesmo tamanho da matriz original, por
                                             // questões óbvias..
        }
    }

    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++)
            cout << matrix_b[i][k] << "  ";
        cout << endl;
    }
    
    return 0;
}
