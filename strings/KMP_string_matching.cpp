#include <bits/stdc++.h>

using namespace std;

#define vi  vector<int>
#define ll  long long

// abaabab

// função para calcular prefixos
vector<int> prefix(string s) {
    int len = s.size();
    vector<int> pi(len);
    for(int i = 1; i < len; i++) {
        int j = pi[i-1];
        while(j > 0 && s[j] != s[i])
            j = pi[j-1];
        if(s[j] == s[i])
            pi[i] = j+1;
    }
    return pi;
}

// retorna os índices iniciais de todos os matchs
vi string_search_all(string t, string p) {
    auto pi = prefix(p);
    vi ans;
    int len = t.size();
    int idx = 0;
    for(int i = 0; i < len; i++) {
        if(p[idx] == t[i]) {
            idx++;
            if(idx == p.size()) {
                ans.push_back(i-idx+1);
                idx = 0;
            }
        } else if(idx > 0) {
            idx = pi[idx-1];
        }
    }

    return ans;
}

// tricks para verificar se há algum match de p em t.
bool string_match(string t, string p) {
    string pattern = p;
    // pq não tiramos o $ e fazemos e >= pattern.size() ?
    // um caso onde isso dá ruim: t = abababaab p = aabaaba
    p.push_back('$');
    p.append(t);
    auto arr = prefix(p);
    for(auto e : arr) {
        if(e == pattern.size())
            return true;
    }
    return false;
}

int main() {
    string s = "rato roeu a roupa do rei de roma";
    string p = "ro";

    auto vet = string_search_all(s, p);

    for(auto index : vet) {
        cout << s.substr(index, p.size()) << endl;
    }

    cout << boolalpha << string_match(s, p) << endl;
    return 0;
}
