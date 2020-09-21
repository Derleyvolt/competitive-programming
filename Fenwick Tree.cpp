/*
   Complexity Query   = O(log n) worst case, O(1) best case, in case of input is a power of 2.
   Complexity Update  = O(log n)
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int BIT[MAXN], n;

void update(int i, int v) {
      for(; i <= n; i += i&-i)
        BIT[i] += v;
}

int query(int v) {
     int sum = 0;
     for(; v > 0; v -= v&-v)
        sum += BIT[v];
     return sum;
}

int main() {
    cin >> n;
    vi arr(n);
    for(int i = 0; i < n; i++)
        arr[i] = i;
    cout << query(5) - query(2) << endl; // query(3, 5)
}
