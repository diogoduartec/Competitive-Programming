/*

    *Soma valor do caminho todos para todos*
    -O grafo e uma arvore, e eu quero saber a soma do caminhos de todos os pares de vertices A B
    -O truque e fazer um DFS que gera uma arvore que "enraizando" um vertice especifico. Cada vertice dessa arvore guarda o numero de caras que estao abaixo contando com ele msm depois. Dai usando um principo de contagem da pra chegar na seguinte formula: carasQueEstaoAbaixo(v) * oRestoDosVerticesDoGrafo * oPesoDaArestaQueUneOsDoisSubgrafos

*/

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define eb emplace_back
#define MAXN 100005
#define VISITED 1
#define MOD 1300031

struct edge{
    int u, v, w;
};

vvi adj;
vi visited;
vi tree;
vector<edge> edges;
edge e;

int n, m;
int u, v, w, a;

int dfs(int u){

    visited[u] = VISITED;
    
    tree[u] = 1;
    for(auto v: adj[u]){
        if(!visited[v]){
            visited[v] = VISITED;
            tree[u] += dfs(v);
        }
    }
    
    return tree[u];
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        adj = vvi(n+1);
        visited = vi(n+1, 0);
        tree = vi(n+1, 0);
        
        for(int i=n; --i;){
            cin >> u >> v >> w;
            edges.eb(edge{u, v, w});
            adj[u].eb(v);
            adj[v].eb(u);
        }
        
        dfs(u);
        int ans = 0;
        
        for(auto e:edges){
            //truque os caras que estao a baixo sempre vao ser menor que os que estao em cima, uma vez que o de cima sempre guarda a soma dos de baixo
            a = min(tree[e.u], tree[e.v]);
            ans = ((((e.w * a)%MOD) * (n-a))%MOD + ans)%MOD;//aplicaçao da formula: carasQueEstaoAbaixo(v) * oRestoDosVerticesDoGrafo * oPesoDaArestaQueUneOsDoisSubgrafos
        }
        cout << ans << endl;
        edges.clear();
    }   
    return 0;
}
