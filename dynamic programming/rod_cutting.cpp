#include <bits/stdc++.h>

using namespace std;

#define vi  vector<int>
#define ii  array<int, 2>
#define ll  long long
#define INF (int)1e9

// ideia similar a de unbounded knapsack

const int maxn = 1e5 + 10;

vector<ii> prices = { {1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20} };

int dp[maxn];

int solve(int w) {
    if(w <= 0)
        return 0;

    if(dp[w] > 0)
        return dp[w];
    int ans = 0;
    for(auto [a, b] : prices) {
        if(w >= a)
            ans = max(ans, solve(w-a) + b);
    }

    return dp[w] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << solve(8) << endl;
    return 0;
}
