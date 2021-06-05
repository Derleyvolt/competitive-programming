
#include <bits/stdc++.h>

using namespace std;

// junta dois subarrays, ambos os arrays
// precisam estar ordenados.. e estarão, graças ao mergesort.
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
        else
            arr[k] = right[j++];
        k++;
    }

    while (i < len1)
        arr[k++] = left[i++];

    while (j < len2)
        arr[k++] = right[j++];
}

// os comentários no mergesort foram todos provados informalmente por mim..
void merge_sort(int arr[], int l, int r) {
    // l nunca é maior que r.
    if(l>=r)
        return;
    // m nunca é menor que l
    int m = (l+r)/2;
    
    // l - m - r
    
    // o intervalo que será passado em cada um dos mergesorts seguintes
    // podem diferir em tamanho, no máximo, em 1.
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);

    // o primeiro merge sempre terá [0..1] como intervalo
    merge(arr, l, m, r);
}

int main() {
    int arr[] = { 1, 3, 2 };
    int n = 3;
    merge_sort(arr, 0, n-1);
    return 0;
}
