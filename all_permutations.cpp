#include <bits/stdc++.h>

using namespace std;

// O(n) pra cada call da next_permutation

void show(vector<int>& arr) {
    for(auto a:arr) cout << a << " ";
    cout << endl;    
}

int main() {
    vector<int> arr = { 1, 2, 3, 4 };
    int cnt = 1;
    show(arr);
    
    // next permutation retorna true enquanto houver permutações pendentes..
    while(next_permutation(arr.begin(), arr.end())) {
        cnt++;
        show(arr);
    }
    
    cout << "quantidade de permutações: " << cnt << endl;
    return 0;
}
