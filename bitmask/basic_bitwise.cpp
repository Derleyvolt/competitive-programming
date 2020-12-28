#include <iostream>

using namespace std;

void show_bits(int v, int s, bool f) {
    if (s == 0)
        return;
    show_bits(v >> 1, s - 1, 0);
    cout << (v & 1);
    if (f)
        cout << endl;
}

int set_bit(int num, int pos) {
    return num | 1 << pos;
}

bool check_bit(int num, int pos) {
    return num & (1 << pos);
}

int clear_bit(int num, int pos) {
    return num & ~(1 << pos);
}

int toggle_bit(int num, int pos) {
    return num ^ (1 << pos);
}

int main() {
    int num, pos; cin >> num >> pos;
    num = clear_bit(num, pos);
    show_bits(num, 8, 1); // mostra os primeiros 8 bits de num
    return 0;
}
