#include <bits/stdc++.h>

using namespace std;

// usando aritmética modular
void rotate(int n) {
     string s = to_string(n);
     string aux = s;
     for(int i = 0; i < s.size(); i++) {
          for(int j = 0; j < s.size(); j++) {
               aux[(i+j) % s.size()] = s[j];
          }
          cout << aux << endl;
     }
}


// usando insert
void rotate_ex(int n) {
    string s = to_string(n);
    cout << s << endl;
    for(int i = 1; i < s.size(); i++) {
        s.insert(0, 1, s.back()), s.pop_back();
        cout << s << endl;
    }
}

int main() {
    int n; cin >> n;
    rotate_ex(n);
}
