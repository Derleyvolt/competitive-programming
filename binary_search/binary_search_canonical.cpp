#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

int arr[maxn];

int n;

int binary_search(int v) {
    int l = 0, r = n-1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(arr[m] == v)
            return arr[m];
        if(arr[m] < v)
            l = m + 1;  
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int v; cin >> v;
    if(binary_search(v) != -1)
        cout << "valor encontrado" << endl;
    else
        cout << "valor nao encontrado" << endl;
    return 0;
}
