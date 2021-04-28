#include <bits/stdc++.h>

using namespace std;

#define endl  '\n'
#define vi  vector<int>

/*
   Não encontrei nenhuma prova na internet de que todas as partições de um vetor de tamanho N em subarrays/substrings estão contidas
   nas 2^n máscaras - apesar do motivo ser intuitivo. Eu acabei elaborando uma prova simples e fácil sobre esse resultado: https://www.overleaf.com/read/zxmvzycqkxrw
 
*/

vi arr = { 1, 2, 3, 4, 5 };

vector<vi> separar(int n) {
    string bits = bitset<5>(n).to_string(); // bitset indexa n como binário a partir do bit mais significativo..
    char c = bits.front();
    vector<vi> ans(1);
    int idx = 0;
    for(auto s : bits) {
        if(s == c)
            ans.back().push_back(idx++);
        else {
            c = s;
            ans.push_back({});
            ans.back().push_back(idx++);
        }
    }

    return ans;
}

int main() {
    int n = arr.size();
    for(int i = 0; i < (1<<n); i++) {
        auto vet = separar(i);
        for(auto v : vet) {
            cout << "[";
            for(int i = 0; i < v.size(); i++) {
                if(i < v.size()-1)
                    cout << arr[v[i]] << ", ";
                else
                    cout << arr[v[i]] << "] ";
            }
        }
        cout << endl;
    }
    return 0;
}
