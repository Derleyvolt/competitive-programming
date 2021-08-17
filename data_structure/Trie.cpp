#include <bits/stdc++.h>

using namespace std;

#define maxn 26

// Esse arquivo ainda será atualizado..

// A construção da Trie requer O(mn), onde m é o tamanho da maior string e n é o número de strings

// A trie consome bastante memória por razões óbvias (linha 14).

struct Trie {
    Trie* node[maxn];
};

Trie* create_trie() {
    Trie* tr = new Trie();
    for(int i = 0; i < maxn; i++) {
        tr->node[i] = nullptr;
    }
    return tr;
}

// O(m), m = tamanho da input string
void insert(Trie* trie, string& s, int idx = 0) {
    if(idx >= s.size())
        return;
    if(trie->node[s[idx]-'a'] == nullptr) {
        trie->node[s[idx]-'a'] = create_trie();
    }

    insert(trie->node[s[idx]-'a'], s, idx+1);
}

// O(m), m = tamanho da string
bool search(Trie* trie, string& s, int idx = 0) { 
    if(idx >= s.size())
        return true;
    if(trie->node[s[idx]-'a'] == nullptr) {
        return false;
    }
    return search(trie->node[s[idx]-'a'], s, idx+1);
}

int main() {
    Trie* tr = create_trie();

    string s = "hello";

    insert(tr, s);
    s = "rato";
    insert(tr, s);
    s = "carro";
    insert(tr, s);

    s = "carr"; // verificando se existe o prefixo/string carr na Trie

    cout << boolalpha << search(tr, s) << endl;
    s = "rato";
    cout << boolalpha << search(tr, s) << endl;
    s = "pato";
    cout << boolalpha << search(tr, s) << endl;
    return 0;
}
