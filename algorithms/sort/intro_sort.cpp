#include <bits/stdc++.h>

using namespace std;

template<typename T>
void insertion_sort(T arr[], int l, int r) {
    int i;
    T aux;
    for (int j = l+1; j <= r; j++) {
        aux = arr[j];
        i = j-1;
        while ((i >= l) && (arr[i] > aux)) {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = aux;
    }
}

template<typename T>
void heap_down(T arr[], int left, int right, int i) {
    int len = right-left+1;
    int l = (i-left)*2+1;
    int r = (i-left)*2+2;

    int temp = i;   

    if(r < len && arr[temp] < arr[r+left])
        temp = r + left;
    if(l < len && arr[temp] < arr[l+left])
        temp = l + left;

    if(temp != i) {
        swap(arr[temp], arr[i]);
        heap_down(arr, left, right, temp);
    }
}

// [l, r]
template<typename T>
void heap_sort(T arr[], int l, int r) {
    for(int i = r; i >= l; i--)
        heap_down(arr, l, r, i);

    for(int i = r; i >= l; i--) {
        swap(arr[l], arr[i]);
        heap_down(arr, l, i-1, l);
    }
}

// Implementação de Lomuto
template<typename T>
int partition(T arr[], int low, int high) {
    int pivot, idx;
    idx   = low;
    pivot = high;

    for(int i=low; i < high; i++) {
        if(arr[i] < arr[pivot]) {
            swap(arr[i], arr[idx]);
            idx++;
        }
    }

    swap(arr[pivot], arr[idx]);
    return idx;
}

// [i, j]
template<typename T>
void intro_sort(T arr[], int i, int j, int h) {
    // caso base
    if(j-i+1 <= 1)
        return;

    // GNU usa insertion sort em partições menores que 16.
    if(j-i+1 < 16) {
        return insertion_sort(arr, i, j);
        //return shell_sort(arr, j-i+1);
    }

    // desceu mt na recursão..
    if(h <= 0) {
        return heap_sort(arr, i, j);
    }

    int pivot = partition(arr, i, j);
    intro_sort(arr, i, pivot-1, h-1);
    intro_sort(arr, pivot+1, j, h-1);
}

bool is_ordered(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}

mt19937 gen(time(NULL));

int random_number_generator(int min, int max) {
    uniform_int_distribution<int> g(min, max);
    return g(gen);
}

int main() {
    int *arr, n;

    cout << "Digite o tamanho do array" << endl;
    cin >> n;

    arr = new int[n];

    for(int i = 0; i < n; i++) {
        arr[i] = RNG(1, 1<<30);
    }

    clock_t t = clock();

    // GNU usa log2(n) * 2 como profundidade máxima, mas isso
    // pode ser modificado
    intro_sort(arr, 0, n-1, log2(n)*2);

    t = clock() - t;

    cout << "tempo: " << ((double)t)/((CLOCKS_PER_SEC)) << " segundos" << endl;

    cout << boolalpha << is_ordered(arr, n) << endl;

    delete[] arr;
    return 0;
}
