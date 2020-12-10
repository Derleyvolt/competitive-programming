#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (a) {
        swap(a, b);
        a = a % b;
    }
    return b;
}

int main() {
    int a, b; cin >> a >> b;
    cout << gcd(a, b) << endl;
}
