#include <bits/stdc++.h>

using namespace std; 

/*
   O número 347, por exemplo, em notação posicional é escrito assim: (3 * 10 ^ 2) + (4 * 10 ^ 1) + (7 * 10 ^ 0).
   Dessa forma, fica fácil perceber que quando dividimos o número pela base, o resto sempre será o termo que é menor que a própria base, ou seja,
   o resto sempre será a unidade. Os outros termos sempre serão maiores e múltiplos da base.
   Portanto, basta pegarmos sempre o resto do número original e multiplicarmos por 10 enquanto, só não podemos multiplicar por 10 quando pegarmos o
   último dígito do número original, o 3, nesse caso, pois ele vai ficar como unidade; para fazermos isso basta não multiplicarmos pela base o último dígito
   ou simplesmente omitirmos a primeira multiplicação pela base, que é o que iremos fazer.
*/

int reverse_n(int n) {
    int r = 0;
    while(n) {
        int q = n % 10;
        n /= 10;
        r *= 10; // multiplicando por 0, ou seja, omitindo a primeira multiplicação pela base.
        r += q;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout << reverse_n(347) << endl;
    return 0;
}
