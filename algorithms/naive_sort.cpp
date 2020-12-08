#include <bits/stdc++.h>

using namespace std; 


mt19937 rg(time(0));

int rng(int min, int max) {
    uniform_int_distribution<int> gen(min, max);
    return gen(rg);
}

void naive_sort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        for(int k = i + 1; k < n; k++) {
            if(arr[i] < arr[k])
                swap(arr[i], arr[k]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    vector<int> arr(100);
    for(auto& a:arr) a = rng(1, 100);
    bubble_sort(arr);
    for(auto a:arr) cout << a << endl;
    return 0;
}
