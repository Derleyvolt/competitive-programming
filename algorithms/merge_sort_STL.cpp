#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

void merge_sort(vector<int>& arr, int l, int r) {
    if(l == r)
        return;
    int m = (l+r)/2;

    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);

    vi a1(arr.begin() + l,   arr.begin() + m+1);
    vi a2(arr.begin() + m+1, arr.begin() + r+1);
    
    // linear em a1.size() + a2.size()
    merge(a1.begin(), a1.end(), a2.begin(), a2.end(), arr.begin() + l);
}

int main() {
    vi arr = {1, 6, 2, 0, -1, 5, -5, 12, 15, 10, 3};
    merge_sort(arr, 0, arr.size() - 1);
    for(auto a:arr) cout << a << " ";
    cout << endl;
}
