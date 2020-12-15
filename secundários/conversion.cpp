#include <bits/stdc++.h>

using namespace std; 

// string
void dec_to_binary(int d) {
    string s;
    for(int i = 0; i < 32; i++) {
        s.append(1, (d & 1));
        d >>= 1;
    }
    reverse(s.begin(), s.end());
    cout << "binary: ";
    for(auto a:s)
        cout << int(a);
    cout << endl;
}

// modo convencional iterativo
void dec_to_b(int d) {
    vector<int> arr;
    while(d) {
        int rem = d % 2;
        d /= 2;
        arr.push_back(rem);
    }
    reverse(arr.begin(), arr.end());
    for(auto& a:arr) cout << a;
    cout << endl;
}

// modo convencional iterativo
void dec_to_hex(int a) {
    string s;
    while(a) {
        int remainder = a % 16;
        a /= 16;
        if(remainder > 9)
            s.append(1, char(55 + remainder));
        else 
            s.append(1, char(48 + remainder));
    }
    reverse(s.begin(), s.end());
    cout << "hex: ";
    cout << s << endl;
}

// modo convencional recursivo
void dec_to_bi(int n) {
    if(n == 0)
        return;
    int r = n % 2;
    n /= 2;
    dec_to_bi(n);
    cout << r;
}

int main() {
    int d; cin >> d;
    dec_to_bi(d);   // recursivo
    dec_to_hex(d);  // iterativo
    dec_to_b(d);    // iterativo
    return 0;
}
