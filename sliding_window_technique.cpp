#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1e5 + 10;

int arr[maxn];

bool sliding_window(int w, int n, int v) { // w = tamanho da janela, n = tamanho do array e v = valor a ser buscado
    if(w > n) return false;

    int ans = 0;
    for(int i = 0; i < w; i++) 
        ans += arr[i];

    if(ans == v) return true;

    for(int i = 0; i < n-w; i++) {
        ans += arr[i + w] - arr[i];
        //assert(cout << ans << endl and i + w <= n-1);
        if(ans == v) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << boolalpha << sliding_window(2, n, 20) << endl;
    return 0;
}
