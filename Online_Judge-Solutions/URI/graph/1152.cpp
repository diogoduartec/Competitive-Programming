#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define MAXM 200005

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

int kruskal(){
	init();
	int ans = 0;
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
		int totalCost = 0;
		for(int i=0; i<m; i++){
			cin >> edges[i].u >> edges[i].v >> edges[i].w;
			totalCost += edges[i].w;
		}
		//sort(edges, edges+m, compare2);
		sort(edges, edges+m, compare1);
		cout << totalCost - kruskal() << endl;
	}
	return 0;
}