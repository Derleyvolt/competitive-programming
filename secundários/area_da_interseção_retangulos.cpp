#include <bits/stdc++.h>

using namespace std; 

struct point {
    int x, y;
};

int intersect(point l1, point r1, point l2, point r2) {
    // verifica se é possível haver interseção
    if(l1.x > r2.x or l2.x > r1.x or l1.y > r2.y or l2.y > r1.y)
        return 0;
    // calcula a base e a altura da intersecção 
    int b = min(r1.x, r2.x) - max(l1.x, l2.x);
    int h = min(r1.y, r2.y) - max(l1.y, l2.y);

    return h * b;
}

int main() {
    int ans = intersect({-2, -2}, {2, 2}, {-4, 1}, {-1, 4});
    cout << ans << endl;
    return 0;
}
