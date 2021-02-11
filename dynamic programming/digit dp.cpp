#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define vi  vector<int>
#define ii  array<int,2>

int dp[200][2];

ll count(int idx, vi& arr) {
     ll ans = 0;
     for(int i = idx+1; i < arr.size(); i++)
          ans = ans * 10 + arr[i];
     return ans + 1;
}

int solve(int idx, bool limit, vi& arr) {
     if(idx >= arr.size())
          return 0;
     int ans = 0;
     int until = limit ? arr[idx]-1 : 9;
     for(int i = 1; i <= until; i++)
          ans += i * pow(10, arr.size()-idx-1) + solve(idx+1, 0, arr);
     if(limit)
          ans += arr[idx] * count(idx, arr) + solve(idx+1, 1, arr); 
     return ans + solve(idx+1, 0, arr);
}

int brute(int n) {
     int ans = 0;
     for(int i = 0; i <= n; i++) {
          string s =  to_string(i);
          for(auto str:s)
               ans += str-'0';
     }
     return ans;
}

int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     vi arr_a = {4};
     vi arr_b = {1, 1};
     cout << solve(0, 1, arr_b) - solve(0, 1, arr_a) << endl;
     return 0;
}
