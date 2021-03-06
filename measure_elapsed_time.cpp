#include <bits/stdc++.h>

using namespace std; 

void running() {
    int until = 4 * 1e8; // geralmente é a quantidade de operações executadas em um segundo em vários online judges
    
    int a = 0;
    
    for(int i = 0; i < until; i++) {
        a = i;
    }
}

int main() {
    auto start = chrono::steady_clock::now();

    running();
    
    auto end = chrono::steady_clock::now();
    
    auto time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Tempo decorrido em milissegundos: " << time << " ms" << endl;
    return 0;
}
