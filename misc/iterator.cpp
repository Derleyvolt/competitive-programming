#include <bits/stdc++.h>

using namespace std;

// TODOS OS ALGORITMOS DO STL NÃO INCLUEM O FINAL DO INTERVALO, OU SEJA, [begin, end).


// 1 - É possível usar iterators literalmente como índices num container
// 2 - É possível mesclar iterators com índices (inteiros).

void ex1() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // arr.begin() + 5 retorna o iterator que aponta pro elemento arr[5].
    auto it = arr.begin() + 5;
}

void ex2() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // inverte o intervalo: arr[5..8] ou arr[5..9)
    reverse(arr.begin() + 5, arr.begin() + 9);
}

void ex3() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // queremos pegar a distância do primeiro elemento ao sexto elemento, intervalo aberto.
    int dist   = distance(arr.begin(), arr.begin() + 5); // distancia em índices
    int dist_1 = arr.begin() + 5 - arr.begin();
    // ambos são equivalentes a: 5 - 0;
  
    int dist_1 = arr.begin() + 5 - arr.begin() + 1; // intervalo fechado.
}

int main() {
    vector<int> arr = { 1, 2, 3, 0, 4, 5, 6, 7, 8, 12, 10 };
    auto it_maior = max_element(arr.begin(), arr.end());
    auto it_menor = min_element(arr.begin(), arr.end());
    cout << abs(it_maior - it_menor) + 1 << endl;
    cout << abs(distance(it_maior, it_menor)) + 1 << endl;
    
    // it_menor - arr.begin() me retorna o índice do elemento 0-indexed.
    cout << "index: " << (it_menor - arr.begin()) << endl;
    
    return 0;
}
