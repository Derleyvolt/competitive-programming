#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define endl  '\n'
#define vi  vector<int>
#define ii  array<int, 2>
#define ll  long long
#define INF (int)1e9

// se S é formada pela concatenação de uma substring G n vezes
// então o vetor pi de KMP terá como tamanho do maior prefixo e
// sufixo terminando em S.size()-1 : |G| * (n-1)
// e, além disso, |G| certamente divide |S|

// Portanto só é necessário provar a volta, ou seja:
// se |G| divide |S| e a função de prefixo tem aquela cara (citada anteriormente)
// então S é formada pela concatenação de G n vezes e o tamanho de G é dado por:
// S.size() - pi.back(); 

// É fácil provar a volta.


// PROBLEMA: https://vjudge.net/problem/POJ-2406

vi prefix_func(string& s) {
    vi pi(s.size());
    for(int i = 1; i < s.size(); i++) {
        int j = pi[i-1];
        while(j > 0 && s[j] != s[i]) {
            j = pi[j-1];
        }

        if(s[j] == s[i]) {
            pi[i] = j+1;
        }
    }

    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(cin >> s && s != ".") {
        vi pi = prefix_func(s);
        int len = s.size()-pi[s.size()-1];

        if(len == 0) {
            cout << 1 << endl;
            continue;
        }

        if(s.size() % len == 0) {
            cout << s.size() / len << endl;
        }
    }
    return 0;
}
