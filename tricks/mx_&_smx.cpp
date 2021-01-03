#include <bits/stdc++.h>

using namespace std;

/*
    É comum nos depararmos com situações onde devemos pegar o maior e o segundo maior elemento de um conjunto de 3 ou 4 elementos..
    eis aqui minha default-way de fazer isso
*/

#define ii pair<int, int>

pair<int, int> comb(ii l, ii r) {
    int a = l.first, b = l.second, c = r.first, d = r.second;
    auto ans = vector<int>{a, b, c, d};
    sort(ans.rbegin(), ans.rend());
    return {ans[0], ans[1]};
}

int main() {
    ii a, b;
    a.first  = 10;
    a.second = 20;
    b.first  = 30;
    b.second = 40;
    auto answ = comb(a, b);
    cout << answ.first << " " << answ.second << endl;
    return 0;
}
