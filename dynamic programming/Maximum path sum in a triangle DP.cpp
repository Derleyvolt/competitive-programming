#include <bits/stdc++.h>

using namespace std;

#define endl  '\n'
#define vi  vector<int>
#define ii  array<int, 2>
#define ll  long long
#define INF (int)1e9

const int maxn = 110;

vector<vector<int>> arr;

int dp[maxn][maxn];

// DP mt simples, bem intuitiva.

int solve(int i, int j) {
    if(i >= arr.size())
        return 0;
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    return dp[i][j] = max(solve(i+1, j), solve(i+1, j+1)) + arr[i][j];
}

int main() {
    for(int i = 0; i < 100; i++) {
        arr.push_back({});
        string s;
        getline(cin, s);
        stringstream str(s);
        while(str >> s) {
            arr[i].push_back(stoi(s));
        }
    }

    memset(dp, -1 , sizeof(dp));

    cout << solve(0, 0) << endl;
    return 0;
}
