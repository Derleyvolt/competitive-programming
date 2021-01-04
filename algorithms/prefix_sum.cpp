#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int arr[maxn];
int psa[maxn];

int n;

void pp() {
    psa[0] = arr[0];
    for(int i = 1; i < n; i++)
        psa[i] = psa[i-1] + arr[i];  
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        cout << arr[i] << " ";
    }
  
    cout << endl;
    
    pp();

    for(int i = 0; i < n; i++)
        cout << psa[i] << " ";   
  
    return 0; 
}
