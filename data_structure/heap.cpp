
#include <bits/stdc++.h>

using namespace std; 

class Heap {
public:
        Heap() = default;
        void  insert(int element);
        void  delete_min();
        int   extract_min();
        int   size();
private:
        vector<int> heap; // implicit data structure

        int   left(int parent);
        int   right(int parent);
        int   parent(int child);
        void  heapifyup(int index);
        void  heapifydown(int index);
};

int Heap::size() {
    return heap.size();
}

void Heap::insert(int element) {
    heap.push_back(element); 
    heapifyup(heap.size() - 1);
}

void Heap::delete_min() {
    if(heap.empty()) {
        cout << "A pilha está vazia" << endl;
        return;
    }
    // poe o último elemento, o elemento mais à direita no último nível, no root da árvore.    
    heap[0] = heap.back();
    heap.pop_back();
        
    heapifydown(0); // reorganiza a árvore de cima pra baixo afim de manter as propriedades da binary heap.
}

int Heap::extract_min() {
    if(heap.empty()) return -1;
    return heap.front();
}

int Heap::left(int parent) {
    int l = 2 * parent + 1;
    if(l < heap.size()) 
        return l;
    return -1;
}

int Heap::right(int parent) {
    int r = 2 * parent + 2;
    if(r < heap.size())
        return r;
    return -1;
}

int Heap::parent(int child) {
    int index = (child-1)/2;
    if(child == 0)
        return -1;
    return index;
}

void Heap::heapifyup(int in) {
    if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in]) {
        swap(heap[in], heap[parent(in)]);
        heapifyup(parent(in));
    }
}

void Heap::heapifydown(int in) {
    int l_child = left(in);  // pega o índice do filho à esquerda
    int r_child = right(in); // pega o índice do filho à direita
    // evitar índices negativos.. short-circuit evita que a segunda 
    // condição seja verificada se a primeira for falsa
    if (l_child >= 0 && r_child >= 0 && heap[l_child] > heap[r_child])
       l_child = r_child;
       
    // vai chamar a função recursivamente até chegar no último nível
    // da árvore, onde o nó não terá mais filhos e l_child seja negativo.
    if (l_child > 0) {
        swap(heap[l_child], heap[in]);
        heapifydown(l_child);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Heap my_priority_queue;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        my_priority_queue.insert(i);
    return 0;
}
