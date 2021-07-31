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

// CONTA O NÚMERO DE OCORRÊNCIAS DOS PREFIXOS DE S NUMA STRING T.

// O(n)
void ocurrence(string s, string p) {
	// o separador # impede a função de prefixo de contar
	// algum prefixo que é sufixo na intersecção de S e P.
	string temp = s + '#' + p;
	auto pi = prefix_function(temp);
	int len = temp.size();
	int n = s.size();

	for(int i = n+1; i < len; i++) {
		// frequências das substrings de p que são prefixos de s.
		freq[pi[i]]++;
	}
	
	// i = n; é importante, pois no caso: s = "aaa", p = "aaaaa"
	// se i = n-1, prefixos não serão contados.
	for(int i = n; i > 0; i--) {
		// verifico se o maior prefixo que é sufixo de s terminando em i-1
		// está em P e, se sim, somo ao número de ocorrências dele o número
		// de ocorrências da substring da qual ele é prefixo e sufixo, pois
		// as ocorrências da substring s[0..i] sombream o prefixo de tamanho
		// pi[i-1].

		// importante verificar que se P não tem o prefixo de tamanho pi[i-1]
		// em s, então o prefixo de tamanho i também não estará em P.
		freq[pi[i-1]] += freq[i];
	}

	for(auto [a, b] : freq) {
		cout << s.substr(0, a) << " freq: " << b << endl;
	}
}

int main() {
	ocurrence("ababaaxx", "xxababdddaxababa");
	return 0;
}
