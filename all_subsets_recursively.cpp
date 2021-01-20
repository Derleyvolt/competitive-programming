#include <bits/stdc++.h>

using namespace std;

vector<int> arr = { 1, 2, 3, 4 };

vector<int> aux;

void subsets(int idx = 0) {
    if (idx >= arr.size()) { 
        for (auto a : aux) cout << a << " ";
        cout << endl; return;
    } 
    aux.push_back(arr[idx]);
    subsets(idx + 1);
    aux.pop_back();
    subsets(idx + 1);
}

int main() {
    subsets();
    return 0;
}
