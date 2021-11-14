#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    return (-1./20)* (x*x) + (1/5. * x) + 100;
}

// A função precisa ser unimodal, ou seja, deve haver um único x cujo f(x) é máximo.
double ternary_search(double l, double r, double eps = 1e-4) {
    double m1 = l + (r-l)/3;
    double m2 = r - (r-l)/3;

    if(fabs(r-l) <= eps) {
        return f(r);
    } else if(f(m1) > f(m2)) {
        r = m2;
    } else {
        l = m1;
    }
}

int main() {
    cout << ternary_search(1.8, 40) << endl;
    cout << f(2) << endl;
    return 0;
}
