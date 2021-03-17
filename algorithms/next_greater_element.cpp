#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

vi ans;

// ans tem o mesmo tamanho que o vetor target, o índice 0 do vetor ans tem o primeiro elemento maior que o 1.
// no índice 3 do vetor ans tem 11, que é o primeiro elemento maior que 8 no vetor original.. etc..

void NGE(vi arr) {
    stack<array<int, 2>> stk; // valor e índice
    for(int i = 0; i < arr.size(); i++) {
        while(not stk.empty() and stk.top()[0] < arr[i]) {
            ans[stk.top()[1]] = arr[i];
            stk.pop();
        }
        stk.push({arr[i], i});
    }
}

int main() {
    vector<int> aux = { 1, 7, 8, 5, 2, 4, 11, 17, 5, 10, 9 };
    ans.resize(aux.size(), -1);
    NGE(aux);
    for(auto a:ans)
        cout << a << endl;
}
