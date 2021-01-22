#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1e6 + 10;

// a fórmula de recorrência pode ser generalizada pra m elementos não adjacentes.. basta trocar o 2 por m
// a fórmula de recorrência basicamente analisa todos os subconjuntos, seguindo as restrições
// a recorrência contém overlapping subproblems, ou seja, um mesmo estado é chamado várias vezes. Portanto podemos "memorizar" essas calls

int dp[maxn], k;

int arr[maxn];

int solve(int n) {
    if(n > k) // >= se for 0-indexed
        return 0;
    if(dp[n]) return dp[n];
    return dp[n] = max(arr[n] + solve(n+2), solve(n+1)); // f(n) = max(a[n] + f(n + 2), f(n + 1))
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    for(int i = 1; i <= k; i++)
        cin >> arr[i];
    cout << solve(1) << endl;
    return 0;
}
