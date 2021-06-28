#include <bits/stdc++.h>

using namespace std;

int dp[1000][1000];

// O(n*k)
int solve(int n, int k) {
    if(dp[n][k] != -1)
        return dp[n][k];
    if(k == 0 or k == n)
        return 1;
    return dp[n][k] = solve(n-1, k-1) + solve(n-1, k); // relação de Stifel
}

int main() {
    memset(dp, -1, sizeof dp);
    cout << solve(17, 7) << endl;
    return 0;
}
