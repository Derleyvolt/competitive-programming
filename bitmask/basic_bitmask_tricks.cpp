#include <bits/stdc++.h>

using namespace std;

void show_bits(int v, int n, bool f) {
    if(n == 0)
        return;
    show_bits(v>>1, n-1, 0);
    if(f)  
        cout << (v&1) << endl;
    else
        cout << (v&1);
}

int union_set(int a, int b) {
    return a | b; // união dos elementos dos conjuntos
}

int intersection_set(int a, int b) {
    return a & b; // o novo conjunto terá 1's apenas onde houver 1's em posições iguais em ambos os conjuntos
}

int difference(int a, int b) { // a ordem é importante, obviamente..
    return (a | b) ^ a;
}

int main() {
    int a = 12, b = 14; // 1100, 1110
    show_bits(union_set(a, b), 4, 1);
    show_bits(intersection_set(a, b), 4, 1);
    show_bits(difference(a, b), 4, 1);
    show_bits(difference(b, a), 4, 1); // difference não é comutativa
    return 0;
}
