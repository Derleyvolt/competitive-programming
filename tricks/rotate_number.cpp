#include <bits/stdc++.h>

using namespace std;

void rotate(int n) {
    string s = to_string(n);
    cout << s << endl;
    for(int i = 1; i < s.size(); i++) {
        s.insert(0, 1, s.back()), s.pop_back();
        cout << s << endl;
    }
}

int main() {
    int n; cin >> n;
    rotate(n);
}
