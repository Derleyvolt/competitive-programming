#include <bits/stdc++.h>

using namespace std; 

#define pii pair<int, int>
#define vi vector<int>

const int maxn = 1e3;

int n;

vector<pii> g[maxn]; // lista de adjacência, contendo os vizinhos e os pesos
vi dist;             // vetor de distância acumulada

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> q; // estrutura de dado built-in do c++ implementada como um heap.. deleção e inserção em O(logn)
    dist.assign(n+1, INT_MAX); // inicialmente todas as distâncias sao infitinas
    dist[s] = 0;               // exceto o source vertex
    q.push({dist[s], s});      // insere no min_heap a distância inicial e o source, respectivamente
    
    while(not q.empty()) {
        auto [d, u] = q.top(); q.pop(); // distância acumulada e o vértice
        
        if(d > dist[u]) continue; // verificação extremamente importante. Bypassing o gargalo que é o fato de serem adicionados à min_heap mais de um
                                  // vértice com distâncias diferentes..
        
        // nesse ponto do algoritmo é garantido que dist[u] guarda a melhor distância de s -> u
        // esse vértice é considerado como fechado, não pode haver nenhum outro com menor distância
        // que dist[u] .. se pensarmos bem, todos os vértices que serão atualizados depois desse vértice u terão sempre
        // peso maior ou igual a u, pq? pq todos os vértices que virão depois de u herdarão o peso dos vértices que estão na 
        // min_heap e são maiores ou iguais a u.. Portanto, dist[u], nesse ponto, é a melhor distância..
        
        for(auto [v, w] : g[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w; // atualiza a distância do source até o vértice v. Essa operação é conhecida como RELAXAMENTO
                q.push({dist[v], v});  // insere na min_heap
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    return 0;
}
