#include <bits/stdc++.h>

using namespace std;

string s1, s2;

// número mínimo de operações necessárias pra s1 tornar-se s2,
// sendo as operações remover, inserir e substituir.

int solve(int i, int j) {
    // s1 > s2, então eu removo (s1.size()-i) caracteres
    if(j >= s2.size())
        return (s1.size()-i);
  
    // s2 > s1, então eu insiro (s2.size()-j) caracteres    
    if(i >= s1.size())
        return (s2.size()-j);

    if(s1[i] == s2[j])
        return solve(i+1, j+1);
    
    // remove, replace e insert, respectivamente.
    return min({solve(i+1, j), solve(i+1, j+1), solve(i, j+1)}) + 1;
}

int main() {
    s1 = "intention";
    s2 = "execution";
    cout << solve(0, 0) << endl;
    return 0;
}
