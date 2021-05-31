#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define vi  vector<int>
#define ii  array<int,2>

const int maxn = 3010;

// A MENOR STRING QUE POSSUI 'A' E 'B' COMO SUBSEQUÊNCIA.

string A = "AGGTAB", B = "GXTXAYB";

int dp[maxn][maxn];

int solve(int idx1, int idx2) {
     if(idx1 >= A.size() or idx2 >= B.size())
          return 0;
     if(dp[idx1][idx2] != -1)
          return dp[idx1][idx2];
     int ans = 0;
     if(A[idx1] == B[idx2])
          ans = solve(idx1+1, idx2+1) + 1;
     else
          ans = max(solve(idx1+1, idx2), solve(idx1, idx2+1));
     return dp[idx1][idx2] = ans;
}

int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     memset(dp, -1, sizeof(dp));
     int aux = solve(0, 0);
     cout << A.size() + B.size() - aux << endl;
     //cout << aux + A.size()-aux + B.size()-aux << endl;
     return 0;
}
