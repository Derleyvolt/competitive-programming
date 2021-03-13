#include <bits/stdc++.h>

using namespace std;

int ans;

void merge(int arr[], int l, int m, int r)
{
    int len1 = m - l + 1; // tamanho do primeiro array
    int len2 = r - m;     // tamanho do segundo array, com arr[m] não incluso.

    int left[len1], right[len2];

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    
    for (int j = 0; j < len2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j])
            arr[k] = left[i++];
        else {
            ans += len-i; // (len1-1) - i + 1;
            arr[k] = right[j++];
        }
        k++;
    }

    while (i < len1)
        arr[k++] = left[i++];

    while (j < len2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[],int l,int r) {
    if(l>=r)
        return;

    int m = (l+r)/2;
  
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr, l, m, r);
}

int main() {
    int arr[] = { 7, 6, 5, 4, 3, 2, 1};
    int n = 7;
    mergeSort(arr, 0, n-1);
    cout << ans << endl;
    return 0;
}
