#include <bits/stdc++.h>

using namespace std; 

int div(string s, int num) {
    int r = 0;
    for(auto a:s) {
        int d = a - '0';
        r = (r * 10 + d) % num;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout << div("341", 3) << endl;
    return 0;
}
