#incldue <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

vector<int> arr;

int dp[maxn];

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
    arr.resize(100);
    for(auto& a:arr) cin >> a;
    
}
