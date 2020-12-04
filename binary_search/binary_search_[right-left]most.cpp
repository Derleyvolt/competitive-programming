#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1e4 + 10;

int arr[maxn], n;

int binary_search_rightmost(int v) {
    int l = 0, r = n-1;
    int ans = -1; // guarda os caras encontrados anteriormente
    while(l <= r) {
        int m = l + (r - l) / 2;
        
        /*
            esse código é útil se quisermos pegar os elementos mais à direita mas somente os que são iguais a v.. no entanto, o outro código é
            mais curto e simples e requer apenas uma verificação pra saber se o cara mais à direita é v.
            if(arr[m] == v) {
                ans = arr[m];
                l = m + 1;
            }
            else if(arr[m] < v)
                l = m + 1;
            else
                r = m - 1;
        */
        
        if(arr[m] <= v) {
            ans = arr[m];  // guarda sempre o valor mais próximo de v, que é >= que v
            l = m + 1;
        } else
            r = m - 1;
    }
    return ans; // se estiver procurando exatamente por v e não pelo maior valor menor que ele basta verificar se ans é == v.
}

int binary_search_leftmost(int v) {
    int l = 0, r = n-1;
    int ans = -1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(arr[m] >= v) {
            ans = arr[m];
            r = m - 1;    
        } else
            l = m + 1;
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
    
    // O algoritmos são bem simples então não vou colocar nenhuma descrição aqui.
    
    int ans = binary_search_rightmost(4); // pega o maior valor <= que 4          
    if(ans != -1)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
