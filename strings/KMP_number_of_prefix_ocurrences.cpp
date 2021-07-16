#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define vi  vector<int>
#define ll  long long

map<int, int> freq;

// função de prefixo
vector<int> prefix(string s) {
    int len = s.size();
    vector<int> pi(len);
    for (int i = 1; i < len; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = pi[j - 1];
        }

        if (s[j] == s[i]) {
            pi[i] = j + 1;
        }
    }
    return pi;
}

// calcula o número de vezes em que os prefixos aparecem na string de modo mais intuitivo mas
// com complexidade pésima, nada prático.
void number_of_prefix_ocurrence_BRUTE(vi pi, string s) {
    for (int i = 1; i < s.size(); i++) {
        int j = pi[i];
        while (j > 0) {
            freq[j]++;
            j = pi[j - 1];
        }
    }
}

// faz o mesmo mas em tempo linear
vector<int> number_of_prefix_ocurrence(vector<int> pi, int n) {
    vector<int> ans(n + 1);
    // calcula a frequência dos maiores prefixos que são sufixos de S[0..i-1]
    for (int i = 0; i < n; i++)
        ans[pi[i]]++;
    
    
    
    // esse segundo for é o coração da coisa, o cálculo do vetor pi 
    // deixa alguns prefixos que terminam em i sombreados pelo maior
    // prefixo que é sufixo que termina em i e, portanto, esses prefixos menores que terminam em i
    // não são contabilizados..
  
    // dessa forma, se temos o tamanho do maior prefixo que também é sufixo de S[0..x]
    // e temos que também existem outros prefixos que também são sufixos de S[0..x]
    // todas as vezes que esse maior prefixo/sufixo aparecer, os menores também apareceram
  
    // o que esse for faz é exatamente isso, ele soma o número de aparições dos maiores prefixos que são
    // sufixos aos prefixos que são prefixos qe terminam no mesmo índice.
    for (int i = n - 1; i > 0; i--)
        ans[pi[i-1]] += ans[i];
    for (int i = 0; i <= n; i++)
        ans[i]++;
    return ans;
}

string rng_string(int n) {
    string s;
    for (int i = 0; i < n; i++) {
        s.push_back('a' + rand() % 7);
    }
    return s;
}

int main() {
    // aababaaaba
    while (1) {
        string t = rng_string(8);
        cout << t << endl;
        auto v = prefix(t);

        auto arr = eef(v, t.size());

         for(int i = 0; i < arr.size(); i++) {
             cout << t.substr(0, i) << " " << arr[i] << endl;
         }

        cout << endl << endl;

        number_of_prefix_ocurrence_BRUTE(v, t);

        for(auto [l, count] : freq) {
            cout << t.substr(0, l) << " " << count+1 << endl;
        }

        system("pause");
        system("cls");

        freq.clear();
    }

    return 0;
}

// abaxxacab a
