#include <bits/stdc++.h>

using namespace std; 

void example(string s = "1 2 3 4 5 6 7 8 9 10") {
	stringstream str(s);
    // str << s; atribuindo s à str
	int num;
	while (str >> num) // >> sobrecarregando pra inteiro
		cout << num << endl;
}

void example_2(string s = "Eu juro solenemente nao fazer nada de bom!") {
	stringstream str(s);
	string word;
    int cnt = 0;
	while (str >> word) { // >> sobrecarregando pra strings
        cout << num << endl;
        cnt++; // contando o número de palavras..
    }
}

int main() {
    // int b; cin >> b; 
    // cin.ignore(); necessário onde será lido um input da maneira usual e depois usarmos getline
    string line;
    getline(cin,line);  // ler o cin-buffer até o newline character e joga em line.
    // a partir daqui usando o stringstream parser
    return 0;
}
