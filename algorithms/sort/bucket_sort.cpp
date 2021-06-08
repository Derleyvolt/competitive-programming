#include <bits/stdc++.h>

using namespace std;

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

const int bucket_count = 100;

// haverá 101 baldes, essa constante pode ser alterada, é literalmente um número mágico, pois não
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
        sort(vet.begin(), vet.end());
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
    srand(time(NULL));

    vector<int> arr(1000);

    for(int& a:arr) a = rand() % 10000;

    bucket_sort(arr);

    cout << boolalpha << is_ordered(arr) << endl;

    for(int e : arr) {
        cout << e << endl;
    }

    return 0;
}
