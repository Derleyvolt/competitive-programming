#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define vi  vector<int>
#define ii  array<int,2>

const int maxn = 3010;

string A = "kdopaskpoadkpsiasdiasdjaojd", B = "dwqijodaisdaoiuhjdsakdakdjsal";

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

// iterativo
string recuperar() {
     int i = 0, j = 0;
     string ans;
     while(i < A.size() and j < B.size()) {
          if(A[i] == B[j]) {
               ans.push_back(A[i]);
               i++;
               j++;
          } else {
               if(dp[i+1][j] > dp[i][j+1]) {
                    i++;
               } else
                    j++;
          }
     }
     return ans;
}

int recuperar_recursivo(int i, int j, string& ans) {
    if(i >= A.size() or j >= B.size())
        return 0;
    if(A[i]==B[j]) {
        ans.push_back(A[i]);
        return recuperar(i+1, j+1);
    } else {
        if(dp[i+1][j] > dp[i][j+1])
            return recuperar(i+1, j);
        else
            return recuperar(i, j+1);
    }
}

int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     memset(dp, -1, sizeof(dp));
     solve(0, 0);
     string ans;
     recuperar_recursivo(0, 0, ans);
     cout << ans << endl;
     return 0;
}
