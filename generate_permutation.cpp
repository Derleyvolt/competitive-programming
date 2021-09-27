#include <bits/stdc++.h>

using namespace std;

// nao há ordem particular na geração das permutações
void permutation(int arr[], int idx, int tam) {
    if(idx >= tam) {
        for(int i = 0; i < tam; i++) {
            cout << arr[i] << " ";
        }
        cout << endl; 
        return;
    }

    for(int i = idx; i < tam; i++) {
        // a primeira troca sempre é redudante, pra
        // garantir que a troca feita no estado anterior seja impressa
        swap(arr[i], arr[idx]);
        permutation(arr, idx+1, tam);
        swap(arr[i], arr[idx]);
    }
}

int main() {
    int arr[] = { 1, 2, 3, 4 };
    permutation(arr, 0, 4);
    return 0;
}
