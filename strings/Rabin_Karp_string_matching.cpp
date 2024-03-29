#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

const int maxn = 1e6 + 10;

const ll m = 1e9 + 7;

// essa base funciona pra qualquer alfabeto ASCII
const ll base = 131;

ll power[maxn];

// tem precomputado os hash dos prefixos do texto
ll prefix_hash[maxn];

// precomputa as potências de 131
void preprocess() {
    power[0] = 1;
    for(int i = 1; i < maxn-2; i++) {
        power[i] = power[i-1] * base % m;
    }
}

vi Rabin_Karp(string P, string S) {
    int pattern_len = P.size();
    int text_len    = S.size();

    // guarda as posições dos matchs
    vi ans;

    prefix_hash[0] = S[0];

    // memoriza via recorrência o hash dos prefixos do texto.
    // com isso é possível comparar qualquer substring do texto, de tamanho pattern_len,
    // com o padrão, em O(1).
    for(int i = 1; i < text_len; i++) {
        prefix_hash[i] = (prefix_hash[i-1] + S[i] * power[i]) % m;
    }

    ll hash_pattern = 0;

    // calcula o hash do padrão, pra comparar posteriormente com as janelas
    for(int i = 0; i < pattern_len; i++) {
        hash_pattern = (hash_pattern + P[i] * power[i]) % m;
    }

    // compara as janelas/substrings de tamanho pattern_len
    
    // percorre n-m+1 hashed windows
    // O(n) pra precomputar as potências da base
    // O(m) pra calcular o hash do padrão
    // O(n-m+1) comparar as janelas
    // Então podemos considerar a complexidade como O(n+m);
    // A operação de módulo e a possibilidade de colisão são os gargalos
    // desse algoritmo em relação ao KMP, mas há outras utilidades
    // advindas da ideia desse algoritmo.
    for(int i = 0; i < text_len - pattern_len+1; i++) {
        ll hs = i > 0 ? (prefix_hash[i+pattern_len-1]-prefix_hash[i-1]+m)%m : prefix_hash[i+pattern_len-1];
        if((hash_pattern*power[i])%m == hs) {
            ans.push_back(i);
        }
    }

    return ans;
}

int main() {
    string text = "O rato roeu a roupa do rei de roma";
    string pattern = "ro";
    preprocess();
    auto arr = Rabin_Karp(pattern, text);
    for(auto a : arr) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
