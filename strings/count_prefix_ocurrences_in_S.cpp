#include <bits/stdc++.h>

using namespace std;

#define vi  vector<int>
#define ll  long long

vi prefix_function(string& s) {
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

map<int, int> freq;

// CONTA O NÚMERO DE OCORRÊNCIAS DOS PREFIXOS DE S em S.

// O(n)
void ocurrence(string s) {
    auto pi = prefix_function(s);

    int n = s.size();

    // conta quantas vezes o prefixo de tamanho
    // pi[i] aparece em S.
    for(int i = 0; i < n; i++) {
        freq[pi[i]]++;
    }

    // soma às ocorrências do prefixo pi[i-1]
    // ás ocorrências do prefixo de tamanho i
    // pois o prefixo de tamanho i sombreia o
    // o prefixo de tamanho pi[i-1]
	
	
    // importante i = n, pois o lado direito o i é usado como tamanho	
    for(int i = n; i > 0; i--) {
        freq[pi[i-1]] += freq[i];
    }

    // adiciona 1 a todos os prefixos de s, pois
    // a função de prefixo só conta prefixos próprios.
    for(int i = 0; i < n; i++) {
        freq[i]++;
    }

	for(auto [a, b] : freq) {
		cout << s.substr(0, a) << " freq: " << b << endl;
	}
}

int main() {
	ocurrence("ababaaxx");
	return 0;
}
