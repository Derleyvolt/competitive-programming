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

// não é necessário..
int query(int a, int b) {
    if(a > 1)
        return query(b) - query(a-1);   
    return query(b);
}

int main() {
    n = 10;
    for(int i = 1; i <= n; i++)
        update(i, i);
    cout << query(3, 5) << endl;
}
