#include <bits/stdc++.h>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    freopen("in.txt", "r", stdin);
    string line;
    getline(cin,line);       // ler todos os caracteres do user input buffer no cin
    istringstream iss(line); // essa classe se encarrega de me passar os dados
    int a;
    while(iss >> a) // passa os dados para a variável a, o >> é sobrecarregado pro tipo inteiro..
        cout << a << endl;
    return 0;
}
