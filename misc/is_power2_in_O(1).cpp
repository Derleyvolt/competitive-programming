#include <bits/stdc++.h>

using namespace std;

int is_power2(int n) {
    // é fácil entender isso sabendo como algumas operações, como a subtração por 1, alteram um número binário.
    return !(n & (n-1));
}

int is_power4(int n) {
    // também é muito fácil de entender..
    return (!(n & (n-1))) && (n & (0x55555555));
}

int main() {
    cout << is_power2(63) << endl;
    cout << is_power2(64) << endl;
    return 0;
}
