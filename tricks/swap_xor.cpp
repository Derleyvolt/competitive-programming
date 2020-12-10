#include <bits/stdc++.h>

using namespace std;

void swap(int& a, int& b) {
    a = a ^ b; // a = a ^ b;
    b = a ^ b; // b = (a ^ b) ^ b ... = a;
    a = a ^ b; // a = (a ^ b) ^ a ..  = b;
}

int main() {
    int a, b; cin >> a >> b;
    swap(a, b);
    cout << a << " " << b << endl;
}
