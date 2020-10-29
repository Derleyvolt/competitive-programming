#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1001;

int parent[maxn], s[maxn];

/*
   OBS: As funções utilizadas na estrutura union-find irão sempre agir somente nos índices fornecidos pelo input.. A função root, por exemplo, vai percorrer
   os pais dos nós/vértices até chegar no nó/vértice representante.. todos esses nós fazem parte do conjunto cujo union-find usará.. A função join faz coisas parecidas,
   chama a função root (qual atua somente nos sobconjuntos disjuntos fornecidos no input) e altera a variável parent e s usando como índice os valores fornecidos como
   parâmetro à função, tais valores também só estarão contidos no conjunto de valores fornecidos pelo input.. Certo, mas qq isso tudo significa? significa que após
   a utilização do buffer parent, s, ou qualquer outro buffer que é acessado utilizando os valores fornecidos pelo input, não é necessário reinicializar totalmente 
   seus valores, apenas nos índices que serão utilizados pelo próximo input.. exemplo:
   
   o primeiro input me dá: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] .. o union-find vai usar de alguma forma esses valores etc.. dai, em vários problemas, no final do caso de teste
   é necessário reinicializar as variáveis buffers; no entanto, como o union find utiliza somente os índices que lhes é fornecido, não precisa se preocupar em zerar os buffers
   completamente, mas apenas nos índices do novo input.. continuando no exemplo.. o primeiro caso de teste vai usar o input supracitado, dai o novo input seria:
   [1, 2, 3, 4, 5, 6], nesse caso, zeremos apenas os buffers nesse range, 1-6, pois o lixo que ficou do caso de teste anterior não afetará o caso de teste atual.
   

*/

void init(int n) {
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        s[i] = 1;
    }
}

int root(int u) {
    if(u == parent[u]) return u;
    return parent[u] = root(parent[u]);
}

void join(int u, int v) {
    u = root(u);
    v = root(v);
    if(u == v) return;
    if(s[u] >= s[v]) swap(u, v);
    parent[u] = v;
    s[v] += s[u];
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    init(n);
    while(m--) {
        int a, b; cin >> a >> b;
        // basta subtrair 1 do número de elementos do conjunto a cada união dos conjuntos disjuntos.
        // A ideia é simples, inicialmente todos os subconjuntos disjuntos têm tamanho 1, então se eu unir qualquer elemento com qualquer outro
        // eu vou ter n-1 conjuntos disjuntos (componentes conexas).. basta verificar que estamos tratando sempre o novo conjunto formado
        // após a união como sendo um único elemento..
        if(root(a) != root(b)) // n -= root(a) != root(b);
          --n;
        join(a, b);
    }
    cout << n << endl;
    return 0;
}
