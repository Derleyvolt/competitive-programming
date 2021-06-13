#include <bits/stdc++.h>

using namespace std;

void heap_down(vector<int>& arr, int n, int i) {
    int l = i*2+1;
    int r = i*2+2;

    int temp = i;   
    // short-circuit, se o elemento for uma folha ele não vai entrar 
    // em nenhum desses if's e a recursão vai parar.
    if(r < n && arr[temp] < arr[r])
        temp = r;
    if(l < n && arr[temp] < arr[l])
        temp = l;

    if(temp != i) {
        swap(arr[temp], arr[i]);
        heap_down(arr, n, temp);
    }
}

void heap_sort(vector<int>& arr) {
    int len = arr.size();
    // no intervalo [len/2, len] só há folhas, não precisamos chamar heap_down pra folhas, elas já são heaps,
    // por definição.
    for(int i = len/2; i >= 0; i--)
        heap_down(arr, i);

    for(int i = len-1; i >= 0; i--) {
        // boto o último elemento da heap no inicio e chamo heap_down pra 
        // obter uma heap novamente..
        swap(arr.front(), arr[i]);
        heap_down(arr, i, 0);
    }

    arr = temp;
}

int main() {
    srand(time(NULL));
    vector<int> arr(20);

    for(auto& a:arr) a = rand() % 1000;

    heap_sort(arr);

    for(auto a:arr) {
        cout << a << endl;
    }

    return 0;
}
