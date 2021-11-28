#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000000

int freq[MAXN];

void counting_sort(int arr[], int n) {
    for(int i = 0; i < MAXN; i++) {
        freq[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        freq[arr[i]-1]++;
    }

    int idx = 0;

    for(int i = 0; i < MAXN; i++) {
        int cnt = freq[i];
        for(int j = 0; j < cnt; j++) {
            arr[idx++] = i+1;
        }
    }
}

int main() {
    int arr[100];
    srand(time(NULL));
    for(int i = 0; i < 30; i++) {
        arr[i] = rand() % 10000;
    }

    counting_sort(arr, 30);

    for(int i = 0; i < 30; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
