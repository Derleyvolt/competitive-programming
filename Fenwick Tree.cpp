/*
   Complexity Query   = O(log n) worst case, O(1) best case, in case of input is a power of 2.
   Complexity Update  = O(log n)
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int BIT[MAXN], n;

void update(int x, int val) {
      for(; x <= n; x += x&-x)
        BIT[x] += val;
}
int query(int x) {
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main() {
    cin >> n;
    vi arr(n);
    for(int i = 0; i < n; i++)
        arr[i] = i;
    cout << query(5) - query(2) << endl; // query(3, 5)
}
