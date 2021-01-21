
#include <bits/stdc++.h>

using namespace std; 

void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        // a cada término desse loop mais interno
        // temos um elemento em sua posição correta no array
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
} 

mt19937 rg(time(0));

int rng(int min, int max) {
    uniform_int_distribution<int> gen(min, max);
    return gen(rg);
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
