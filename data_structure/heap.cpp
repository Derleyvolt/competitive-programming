
#include <bits/stdc++.h>

using namespace std; 

/*
    13/11/2020 - 05:01 da manhã
    
    Complexidade:
    heapifydown(int index) = Log(n), pode precisar percorrer todos os níveis da árvore, e a altura duma árvore binária completa é Log(n), n é o número de vértiece/nodes
    heapifyup(int index)   = Log(n)
    
    A criação da heap tem complexidade O(nlog(n)). A função heapifyup será chamada n vezes dentro da função insert
    
    Proriedades:
      Uma binary heap é uma árvore completa, ou seja, todos os níveis da árvore são cheios, com exceção do último que pode ou não ser cheio.
      O número máximo de elementos que uma binary heap 0-indexada pode ter é 2^(h-1) - 1, onde h é a altura. 
            https://www.quora.com/The-height-of-any-binary-tree-of-n-nodes-is-between-log-n-and-n-1-What-is-the-proof-for-this-observation)
      
      O último nível de uma Heap tem seus elementos todos sempre mais à esquerda, se o último nível não estiver cheio. É fácil entender o motivo.
      
      A heap é parcialmente ordenada, o que significa, basicamente, que a relação se dá entre pais e filhos mas não precisa acontencer entre nós irmãos
      ou nós primos.. https://hyosup0513.github.io/data%20structure/2020/06/14/What-is-a-Heap.html
                      https://www.hackerearth.com/practice/notes/heaps-and-priority-queues/
      
    O filho à esquerda é obtido assim: left_child  = 2 * i + 1
    O filho à direita é obtido assim:  right_child = 2 * i + 2
    o nó pai é obtido assim:           parent      = (child - 1) / 2             
*/

template<class T = greater<int>> // max-heap por padrão
class Heap {
public:
        Heap() = default;
        void  insert(int element);
        void  delete_max();
        int   extract_max();
        int   size();
private:
        
        vector<int> heap; // implicit data structure
        int   left(int parent);
        int   right(int parent);
        int   parent(int child);
        void  heapifyup(int index);
        void  heapifydown(int index);
};

template<class T>
int Heap<T>::size() {
    return heap.size();
}

template<class T>
void Heap<T>::insert(int element) {
    heap.push_back(element); 
    heapifyup(heap.size() - 1); // o vector nunca será 0 nesse ponto, portanto nunca ocorrerá um underflow/wrap around no unsigned int.
}

template<class T>
void Heap<T>::delete_max() {
    if(heap.empty()) {
        cout << "A pilha está vazia" << endl;
        return;
    }
    // poe o último elemento, o elemento mais à direita no último nível, no root da árvore.    
    heap[0] = heap.back();
    heap.pop_back();
        
    heapifydown(0); // reorganiza a árvore de cima pra baixo afim de manter as propriedades da binary heap.
}

template<class T>
int Heap<T>::extract_max() {
    if(heap.empty()) return -1;
    return heap.front();
}

template<class T>
int Heap<T>::left(int parent) {
    int l = 2 * parent + 1;
    if(l < heap.size()) 
        return l;
    return -1;
}

template<class T>
int Heap<T>::right(int parent) {
    int r = 2 * parent + 2;
    if(r < heap.size())
        return r;
    return -1;
}

template<class T>
int Heap<T>::parent(int child) {
    int index = (child-1)/2;
    if(child == 0)
        return -1;
    return index;
}

// atualiza a árvore de baixo pra cima

template<class T>
void Heap<T>::heapifyup(int in) {
    if (in >= 0 && parent(in) >= 0 && not T()(heap[parent(in)], heap[in])) {
        swap(heap[in], heap[parent(in)]);
        heapifyup(parent(in));
    }
}

// atualiza a árvore de cima pra baixo
template<class T>
void Heap<T>::heapifydown(int in) {
    int l_child = left(in);  // pega o índice do filho à esquerda
    int r_child = right(in); // pega o índice do filho à direita
    // evitar índices negativos.. short-circuit evita que a segunda 
    // condição seja verificada se a primeira for falsa
    if (l_child >= 0 && r_child >= 0 && not T()(heap[l_child], heap[r_child]))
        l_child = r_child;
       
    // vai chamar a função recursivamente até chegar no último nível
    // da árvore, onde o nó não terá mais filhos e l_child seja negativo.
    if (l_child > 0) {
        swap(heap[l_child], heap[in]);
        heapifydown(l_child);
    }
}

int main() {
    Heap<> my_priority_queue;
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        my_priority_queue.insert(i);
	for(auto a:my_priority_queue.heap) cout << a << endl;
    return 0;
}
