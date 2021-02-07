#include <iostream>
#include <vector>

using namespace std;

#define inf (1<<30)

vector<int> arr;

int n;

// maior state-space.. 
int solve(int idx, int w, int cnt) {
    if (w == 0)
      return cnt;
    if (idx >= n or w < 0)
      return 0;
    int ans = 0;
    ans = max(ans, solve(idx + 1, w - arr[idx], cnt + 1));
    return max(ans, solve(idx + 1, w, cnt));
}

// menor state-space..
int solves(int idx, int w) {
    if (w == 0)
      return 0;
    if (idx >= n or w < 0)
      return -inf;
    return max(solves(idx + 1, w - arr[idx]) + 1, solves(idx + 1, w));
}

int main() {
    freopen("in.txt", "r", stdin);
    int w; cin >> w >> n;
    arr.resize(n);
    for (auto& a : arr) cin >> a;
    cout << solves(0, w) << endl;
    cout << solve(0, w, 0) << endl;
}
