#include <bits/stdc++.h>

using namespace std;

void separate(string& s) {
    string ans;
    char c = s.front();
    for(auto a:s) {
        if(a == c)
            ans.push_back(a);
        else {
            cout << ans << endl;
            ans.clear();
            c = a;
            ans.push_back(a);
        }
    }
    cout << ans << endl; // os couts só são chamados no else do for-range, porém, quando estamos processando o último grupo de itens o bloco do else nunca será chamado
                         // outro cenário seria onde todos os itens são iguais.. o bloco do else nunca seria chamado. 
}

int main() {
    string s; // AAABBBCCCCDDDDEEFFGHIJJJJJKKKKLLLEEERRRGGGHHHAAABBCCC
    separate(s);
    return 0;
}
