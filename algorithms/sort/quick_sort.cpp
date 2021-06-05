#include <bits/stdc++.h>

using namespace std;
 
// O coração desse algoritmo ta na partição

// particiona o array, de tal forma que o pivor, o último elemento do intervalo [low, high] nesse caso, 
// terminará na mesma posição que ele estaria caso o array estivesse ordenado, pois todos os elementos menores que ele
// ficarão antes dele e os maiores após ele.
int Partition(vector<int>& arr, int low, int high) {
    int pivot, idx;
    idx   = low;
    pivot = high;

    for(int i=low; i < high; i++) {
        if(arr[i] < arr[pivot]) {
            swap(arr[i], arr[idx]);
            idx++;
        }
    }

    // troca o valor do pivor com o primeiro cara da esquerda pra direita que é maior que o pivor.
    swap(arr[pivot], arr[idx]);
    return idx;
}
 
void quick_sort(vector<int>& arr, int low, int high) {
    int idx;

    if(low < high) {
        idx = Partition(arr, low, high);

        // chama quick_sort recurisvamente para as duas metades do intervalo
        quick_sort(arr, low, idx-1);
        quick_sort(arr, idx+1, high);
    }
}

int main() {
    vector<int> arr = { 5, 3, 2, 1, 4, 9, 8, 72, 51 };

    quick_sort(arr, 0, arr.size()-1);

    for(auto e : arr) {
        cout << e << endl;
    }

    return 0;
}
	
