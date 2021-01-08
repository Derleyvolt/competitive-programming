#include <bits/stdc++.h>

using namespace std;

vector<int> arr = { 1, 2, 3, 4, 5 };

// O(2^n)

void subsets(int n = arr.size()) {
    for (int i = 0; i < (1 << n); i++) {
        // pegando apenas os subconjuntos com 3 elementos
        //if (__builtin_popcount(i) != 3)
        //    continue;
        int cnt = 0;
        if (i)
            cout << "[";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                if (cnt and j != n - 1)
                    cout << ", ";
                cout << arr[j];
                cnt++;
            }
        }
        if (i)
            cout << "]" << endl;
    }
}

int main() {
    subsets();
    return 0;
}
