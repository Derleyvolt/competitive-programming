#include <bits/stdc++.h>

using namespace std; 

int main() {
    auto start = chrono::steady_clock::now();
 
    int a = 0;

    int time = 4 * 1e8;

    for(int i = 0; i < time; i++) {
        a = i;
    }

    auto end = chrono::steady_clock::now();
    
    auto tempo = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Tempo decorrido em milisegundos : " << tempo << " ms" << endl;
    return 0;
}
