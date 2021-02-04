#incldue <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

vector<int> arr;

int dp[maxn];

int ans;

//N(n^2)

// recursivo
void solve(int idx=1) {
     if(idx >= arr.size())
          return;
     dp[idx] = 1; // é importante isso ser 1
     for(int i = 0; i < idx; i++) {
          if(arr[i] < arr[idx]) {
               dp[idx] = max(dp[idx], dp[i]+1);
          }
     }
     ans = max(ans, dp[idx]);
     solve(idx+1); // tail recursion, boa.
}

int solve() {
    int ans = 1;
    dp[0]   = 1;
    for(int i = 0; i < arr.size(); i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(idx[j] < idx[i]) {
                dp[i] = max(dp[i], dp[j]+1);
                ans   = max(ans, dp[i]);
            }
        }
    }
    return ans;
}

int main() {
     //...
}
