#include <bits/stdc++.h>

using namespace std; 

// constrói o número a partir dos dígitos, exatamente como se estivéssemos construindo o número a partir da notação posicional

int remainder(string s, int num) {
    int r = 0;
    for(auto a:s) {
        int d = a - '0';
        r = (r * 10 + d) % num;
    }
    return r;
}

int main() {
    cout << remainder("341", 3) << endl;
    return 0;
}
