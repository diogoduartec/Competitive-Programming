#include <bits/stdc++.h>
using namespace std;

#define MAXN 400005
#define MAXM 500005
#define i64 long long

typedef struct{
	int u, v, w;
}Edge;

int parent[MAXN], n, m;
Edge edges[MAXM];

void init(){
	for(int i = 0; i<=n; i++) parent[i] = i;
}

int compare1(Edge a, Edge b){
	return a.w < b.w;
}
int compare2(Edge a, Edge b){
	return a.w > b.w;
}

int id(int u){
	return (parent[u]==u ? u : parent[u] = id(parent[u]));
}

void join(int u, int v){
	parent[id(u)] = id(v);
}

i64 kruskal(){
	i64 ans = 0;
	init();
	sort(edges, edges+m, compare1);
	for(int i=0; i<m; i++){
		Edge e = edges[i];
		if(id(e.u) != id(e.v)){
			join(e.u, e.v);
			ans += e.w;
		}
	}
	return ans;
}

int main(){
	while((cin >> n >> m) && n+m){
		for(int i=0; i<m; i++){
			cin >> edges[i].u >> edges[i].v >> edges[i].w;
		}
		cout << kruskal() << endl;
	}
	return 0;
}