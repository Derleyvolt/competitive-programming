#include <bits/stdc++.h>

using namespace std;

#define vii vector<array<int, 2>>

int n;
vector<int> arr;

// O(sqrt(n))
void sqrt_decomp() {
    int len = (int)sqrt(n) + 1; // size of the block and the number of blocks
    vector<int> b(len);
    // em cada índice do vetor b terá o somatório de len elementos consecutivos.. exceto, possivelmente, no último bloco, 
    // caso n não seja múltiplo de ceil(sqrt(n)).
    for (int i = 0; i < n; i++)
        b[i / len] += arr[i];

    // toda posição que for múltipla de len será o início de um bloco..    

    // consultas..
    for(auto [l, r] : vii{ {0, 1}, {1, 3}, {0, 4}, {0, 6} }) {
        int ans = 0;
        for (int i = l; i <= r;) {
            // verifica se i é múltiplo de len, se sim, l aponta pro inicio de um bloco.
            // além disso, precisamos verificar se o intervalo [l, r] engloba inteiramente
            // o bloco iniciando em l e terminando em i + len -1...
            if (i % len == 0 && i + len - 1 <= r) {
                ans += b[i / len];
                i += len;
            }
            else {
                // essa parte do código será linear nos extremos do intervalo
                // se l e r não estão no ínicio e no final de um bloco, respectivamente.
                ans += arr[i];
                ++i;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    n = 10;
    arr = { 1, 6, 5, 4, 7, 8, 9, 11, 1, 2 };
    sqrt_decomp();
    return 0;
}
