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

      A heap é parcialmente ordenada, o que significa, basicamente, que a relação se dá entre pais e filhos mas não entre nós irmãos
      ou nós primos.. https://hyosup0513.github.io/data%20structure/2020/06/14/What-is-a-Heap.html
                      https://www.hackerearth.com/practice/notes/heaps-and-priority-queues/
		      http://pages.cs.wisc.edu/~mcw/cs367/lectures/heaps.html
		      
    O filho à esquerda é obtido assim: left_child  = 2 * i + 1
    O filho à direita é obtido assim:  right_child = 2 * i + 2
    o nó pai é obtido assim:           parent      = (child - 1) / 2
*/

template<typename T = greater<int>> // max-heap por default
class Heap {
public:
    Heap() = default;
    void  push(int element);
    void  pop();
    int   top();
    int   size();
private:
    T comp; // comparator.. define se é um max ou min heap.

    int   left(int parent);
    int   right(int parent);
    int   parent(int child);
    void  heapifyup(int index);
    void  heapifydown(int index);

    vector<int> heap; // implicit data structure
};

template<typename T>
int Heap<T>::size() {
    return heap.size();
}

template<typename T>
void Heap<T>::push(int element) {
    heap.push_back(element);
    heapifyup(heap.size() - 1); // o vector nunca será 0 nesse ponto, portanto nunca ocorrerá um underflow/wrap around no unsigned int.
}

template<typename T>
void Heap<T>::pop() {
    if (heap.empty()) {
        cout << "A pilha está vazia" << endl;
        return;
    }
    // poe o último elemento, o elemento mais à direita no último nível, no root da árvore.    
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();

    heapifydown(0); // reorganiza a árvore de cima pra baixo afim de manter as propriedades da binary heap.
}

template<typename T>
int Heap<T>::top() {
    if (heap.empty()) return -1;
    return heap.front();
}

template<typename T>
int Heap<T>::left(int parent) {
    int l = 2 * parent + 1;
    if (l < (int)heap.size())
        return l;
    return -1;
}

template<typename T>
int Heap<T>::right(int parent) {
    int r = 2 * parent + 2;
    if (r < (int)heap.size())
        return r;
    return -1;
}

template<typename T>
int Heap<T>::parent(int child) {
    int index = (child - 1) / 2;
    if (child == 0)
        return -1;
    return index;
}

template<typename T>
void Heap<T>::heapifyup(int in) {
    if (in >= 0 && parent(in) >= 0 && comp(heap[in], heap[parent(in)])) {
        swap(heap[in], heap[parent(in)]);
        heapifyup(parent(in));
    }
}

template<typename T>
void Heap<T>::heapifydown(int index) {
    int l_child = left(in);
    int r_child = right(in);
    int temp    = index;

    if (l_child >= 0 and r_child >= 0 and comp(heap[r_child], heap[temp]))
        temp = r_child;
    if (l_child >= 0 and r_child >= 0 and comp(heap[l_child], heap[temp]))
        temp = l_child;

    if (temp != in) {
        swap(heap[in], heap[temp]);
        heapifydown(temp);
    }
}

int main() {
    Heap my_priority_queue;
    // Heap<less<int>> .. passando o less<int> comparator a class torna-se uma min_heap	

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        my_priority_queue.push(i);
	
    for (int i = 0; i < n; i++) {
        cout << my_priority_queue.top() << " ";
        my_priority_queue.pop();
    }
	
    return 0;
}


/*
    comparações com a priority_queue heap-based da STL

    int main() {
        Heap<greater<int>> my_priority_queue;
        priority_queue<array<int, 3>> pq;

        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            my_priority_queue.push(i);
            pq.push({i, 1, 1});
        }
        for (int i = 0; i < 5; i++) {
            my_priority_queue.pop();
            pq.pop();
        }
        for (int i = 50; i < 55; i++) {
            my_priority_queue.push(i);
            pq.push({i, 2, 2});
        }

        int s = my_priority_queue.heap.size();
        for (int i = 0; i < s; i++) {
            cout << my_priority_queue.top() << endl;
            my_priority_queue.pop();
        }
        cout << endl;
        cout << endl;
        int size = pq.size();
        for (int i = 0; i < size; i++) {
            auto r = pq.top();
            cout << r[0] << " " << r[1] << " " << r[2] << endl;
            pq.pop();
        }
        return 0;
    }
*/
