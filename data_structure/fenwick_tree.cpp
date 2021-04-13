/*
   Complexity Query   = O(log n) worst case, O(1) best case, in case of input is a power of 2.
   Complexity Update  = O(log n)
*/

#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

int n;

vi BIT, arr;

void update(int i, int v) {
      for(++i; i <= n; i += i&-i)
        BIT[i] += v;
}

int query(int v) {
     int sum = 0;
     for(++i; v > 0; v -= v&-v)
        sum += BIT[v];
     return sum;
}

int query(int l, int r) {
    return query(r) - query(l-1);
}

int main() {
   cin >> n;
   arr.resize(n);
   BIT.resize(n+1);
   for(int i = 0; i < n; i++) {
       cin >> arr[i];
       update(i, arr[i]);
   }
   
   // query -> [2, 4]
   cout << query(2, 4) << endl;
}
