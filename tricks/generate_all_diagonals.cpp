#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

const int dim = 4; // as dimensões da matriz..

vector<vector<int>> matrix;

vi right_diagonal(int r, int c) {
    vector<int> ans;
    while(r < dim and c < dim)
        ans.push_back(matrix[r++][c++]);
    return ans;
}

vi left_diagonal(int r, int c) {
    vector<int> ans;
    while(r < dim and c >= 0)
        ans.push_back(matrix[r++][c++]);
    return ans;
}

void print__(vector<int> arr) {
    for(auto a:arr) cout << a << " ";
    cout << endl;
}

int main() {
    matrix.resize(dim);
    for(auto& a:arr) a.resize(dim);
    
    // ler a matriz do cin-buffer.
    
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // todas as diagonais à direita
    
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            print__(right_diagonal(i, j);
        }
    }
    
    // todas as diagonais à esquerda
    
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            print__(left_diagonal(i, j);
        }
    }
    
    return 0;
}
