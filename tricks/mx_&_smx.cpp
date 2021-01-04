#include <bits/stdc++.h>

using namespace std;

// Motivação https://www.spoj.com/problems/KGSS/

/*
    É comum nos depararmos com situações onde devemos pegar o maior e o segundo maior elemento de um conjunto de 3 ou 4 elementos..
    eis aqui minha default-way de fazer isso. a complexidade do sort não causa overhead por conta da quantidade de elementos, então funciona bem.
*/

#define ii array<int, 2> // array, diferentemente de pair, não é inicializado quando instanciado na stack..
#define vi vector<int>

ii comb_1(ii l, ii r) {
    auto ans = vi{ l[0], l[1], r[0], r[1] };
    sort(ans.rbegin(), ans.rend());
    return { ans[0], ans[1] };
}

/*
    Um outro modo de fazer o mesmo, mas usando heap.. um pouco overkill, na minha opinião.
*/

ii comb_2(ii l, ii r) {
    priority_queue<int> q;
    q.push(l[0]);
    q.push(l[1]);
    q.push(r[0]);
    q.push(r[1]);
    int a = q.top(); q.pop();
    int b = q.top(); q.pop();
    return { a, b };
}

int main() {
    ii a, b;
    a[0] = 10;
    a[1] = 20;
    b[0] = 30;
    b[1] = 40;
    auto answ = comb_1(a, b);
    cout << answ[0] << " " << answ[1] << endl;
    return 0;
}
