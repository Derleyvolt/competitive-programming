#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1e4 + 10;

int arr[maxn], n;

int binary_search_rightmost(int v) {
    int l = 0, r = n-1;
    int ans = -1; // variável que guardará o primeiro cara que é maior que o valor buscado
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(arr[m] == v)
            return m;
        if(arr[m] > v) {
            ans = m; // guarda sempre o valor mais próximo de v, que é maior que v
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}

int binary_search_leftmost(int v) {
    int l = 0, r = n-1;
    int ans = -1; // variável que guardará o primeiro cara que é menor que o valor buscado
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(arr[m] == v)
            return m;
        if(arr[m] < v) {
            ans = m; // guarda sempre o valor mais próximo de v, que é menor que v
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ans;
}

int main() {
    n = 5;
    arr[0] = 1; 
    arr[1] = 2;
    arr[2] = 3; 
    arr[3] = 5;  
    arr[4] = 6;
    
    // A explicação daqui é destinado à função binary_search_rightmost.. a explicação pra função binary_search_leftmost é análoga.
    
    // queremos buscar pelo valor 3.. então colocamos pra encontrar o valor 4, pois o algoritmo vai buscar
    // pelo valor imediato que for >= 4.. ou seja, se o 4 estiver no array, o 4 será encontrado, senão, o próximo
    // valor maior que ele será encontrado. E com isso, se o valor 3 estiver no array, ele deve estar um índice a menos
    // que o valor encontrado.
    int index = bb_2(4) - 1;          
    if(index >= 0 and arr[index] == 3)
        cout << index << endl;
    else
        cout << -1 << endl;
    return 0;
}
