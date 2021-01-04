#include <bits/stdc++.h>

using namespace std; 

// Maximum Subarray Sum

int kadane(vector<int>& arr) {
    int max_cur = 0, max_total = -1;
    for(auto a:arr) {
        max_cur += a;
        if(max_cur < 0) // se o somatório até ali não é positivo então não compensa eu adicionar max_cur ao somatório após isso..
            max_cur = 0;
        if(max_cur > max_total)
            max_total = max_cur;
    }
    cout << max_total << endl;
}

int main() {
    vector<int> arr = { 1, 2, 3, -5, -10, 1, 2, 3, 4, 5, 6, 7 };
    kadane(arr);
    return 0;
}
