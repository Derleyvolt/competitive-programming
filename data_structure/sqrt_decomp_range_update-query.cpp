#include <bits/stdc++.h>

using namespace std;

#define endl  '\n'
#define vi  vector<ll>
#define ii  array<ll, 2>
#define ll  long long
#define INF (int)1e9

vi arr;

int n, cnt;

// O(sqrt(n)) pra atualizar e responder.

// problema teste: https://www.urionlinejudge.com.br/judge/pt/problems/view/1500

void sqrt_decomp() {
    int len = int(sqrt(n)) + 1; // len = 3
    vi b(len), c(len); // O bloco c guarda atualizações em range e o bloco b guarda atualizações individuais
                       // pois, na hora de responder, o bloco c nos dará apenas os valores que foram atribuídos aquele
                       // intervalo.. e se houvesse, dentro daquele intervalo, uma atualização pontual (L==R)? O bloco c não
                       // teria essa informação.. pra isso serve o bloco b.
                       
    while(cnt--) {
        int t; cin >> t;
        if(t == 0) {
            int l, r, v; cin >> l >> r >> v;
            l--, r--; // 0 indexado
            for(int i = l; i <= r;) {
                if(i % len == 0 and i + len-1 <= r) {
                    c[i/len] += v; // atualização nos blocos
                    i += len;
                } else {
                    arr[i]   += v; // atualização nos extremos do range
                    b[i/len] += v;
                    i++;
                }
            }
        } else {
            int l, r; cin >> l >> r;
            l--, r--; // 0 indexado
            ll ans = 0;
            for(int i = l; i <= r;) {
                if(i % len == 0 and i + len-1 <= r) {
                    ans += c[i/len] * len + b[i/len]; // c[i/len] * len nos dá o somatório de todos os acrescimos que foram atribuídos aquele intervalo 
                                                      // b[i/len] nos dá o somatório de todos os acrescimos individuais que foram atríbuidos a índices
                                                      // contidos naquele intervalo, pois o bloco c não gerencia esses.
                    i += len;
                } else {
                    ans += arr[i] + c[i/len];
                    i++;
                }
            }
            cout << ans << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cin >> n >> cnt;
        arr.assign(n, 0);
        sqrt_decomp();
    }
    return 0;
}
