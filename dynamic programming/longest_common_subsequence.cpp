#include <bits/stdc++.h>

using namespace std;

#define vi  vector<int>

string A = "dijawodhuhdaodjopaskxoiajmoikan141541514dmhwu8awudandij216515614854178613da,kmaosjçajdidkasjmskdamdsamldsmadasmld", 
       B = "dij2oospidaojsoajmoidmasjoijndausijndasda5411854154dasdsa5d1a5d1a8dd87a4dadadasd8asd7as1da85d41874dkasmdsoajodas";

int dp[300][300];

int solve(int idxA, int idxB) {
    if(idxA >= A.size() || idxB >= B.size())
        return 0;
    if(dp[idxA][idxB] != -1)
        return dp[idxA][idxB];
    int ans = 0;
    if(A[idxA] == B[idxB])
        ans = solve(idxA+1, idxB+1) + 1;
    return dp[idxA][idxB] = max({ans, solve(idxA+1, idxB), solve(idxA, idxB+1)});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cout << solve2(0, 0) << endl;
    return 0;
}
