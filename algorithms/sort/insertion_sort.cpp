#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int arr[], int n) {
    int aux, i;
    for (int j = 1; j < n; j++) {
        aux = arr[j];
        i = j-1;
        while ((i >= 0) && (arr[i] > aux)) {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = aux;
    }
}

int main() {
    int arr[] = {1, 5, 7, 1, 2, 3, 4, 9, 8 };
    insertion_sort(arr, 9);
    for(auto a:arr) cout << a << endl;
    return 0;
}
