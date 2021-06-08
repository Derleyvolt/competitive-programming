#include <bits/stdc++.h>

using namespace std;

// O(n^2) mas tem O(n) como melhor caso.
void insertion_sort(vector<int>& arr) {
    int aux, i, len = arr.size();
    for (int j = 1; j < len; j++) {
        aux = arr[j];
        i = j-1;
        while ((i >= 0) && (arr[i] > aux)) {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = aux;
    }
}

void debug_buckets(vector<vector<int>>& buckets) {
    int len = buckets.size();
    for(int i = 0; i < len; i++) {
        int len2 = buckets[i].size();
        if(len2)
            cout << "bucket " << i << " -> [";
        for(int j = 0; j < len2; j++) {
            if(j < len2-1)
                cout << buckets[i][j] << ", ";
            else {
                cout << buckets[i][j] << "]" << endl;
            }
        }
    }
}

bool is_ordered(vector<int>& arr) {
    int len = arr.size();
    for(int i = 0; i < len-1; i++) {
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}

// fiz testes com 1e5 ~ 1e6 elementos.. 
const int bucket_count = 10000;

// haverá 10001 baldes, essa constante pode ser alterada, é literalmente um número mágico, pois não
// fiz nenhuma análise em cima disso..

// a expressão (bucket_count * e/maxim) me garante a seguinte propriedade:
// se o elemento x cair no balde de índice p, então qualquer elemento maior ou igual que x caíra ou no mesmo balde que ele
// ou num balde com índice maior.
// essa propriedade é essencial, do contrário não haveria como juntar os buckets pra forjar o array ordenado tão facilmente..

void bucket_sort(vector<int>& arr) {
    int max_e = *max_element(arr.begin(), arr.end());

    vector<vector<int>> buckets(bucket_count+1);

    for(int e : arr) {
        buckets[bucket_count * e/max_e].push_back(e);
    }

    // ordena os buckets
    for(auto& vet : buckets) {
        // O bucket_sort geralmente é utilizado em conjunto com o InsertionSort,
        // pois o InsertionSort tem melhor caso linear, e o melhor
        // caso surge quando os elementos estão quase ordenados..
        insertion_sort(vet);
        
        
        //heap_sort(vet);
        //merge_sort(vet);
        //quick_sort(vet);
    }

    //debug_buckets(buckets);

    // merge os buckets em O(n)
    int idx = 0;
    for(auto& vet : buckets) {
        for(int e : vet) {
            arr[idx++] = e;
        }
    }
}

int main() {
    int len;
    cout << "Digite o tamanho do vetor" << endl;
    cin >> len;

    srand(time(NULL));
    vector<int> arr(len);

    for(int i = 0; i < len; i++) arr[i] = rand() % 10000000;
    
    clock_t t = clock();

    bucket_sort(arr);

    t = clock() - t;

    cout << "Tempo de execucao: " << ((double)t)/((CLOCKS_PER_SEC)) << " milisegundos" << endl;
    cout << boolalpha << is_ordered(arr) << endl;
    return 0;
}
