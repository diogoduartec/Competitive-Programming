#include <bits/stdc++.h>
using namespace std;

#define MAXN 65
#define MAXM 205

struct Edge{
	int u, v, w;
};

int m, n, parent[MAXN];
Edge edges[MAXM];

int compare(Edge a, Edge b){
	return a.w < b.w;
}

void init(int n){
	for(int i=0; i<=n; i++) parent[i] = i;
}

int id(int v){
	return (parent[v]==v ? v : parent[v] = id(parent[v]));
}

void join(int u, int v){
	parent[id(u)] = id(v);
}

int kruskal(){
	int ans = 0;
	init(n);
	sort(edges, edges+m, compare);
	for(int i=0; i<m; i++){
		Edge e = edges[i];
		if(id(e.u) != id(e.v)){
			join(e.u, e.v);
			ans+=e.w;
		}
	}
	return ans;
}


int main(){
	while(cin >> n >> m){
		for(int i=0; i<m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
		cout << kruskal() << endl;
	}
	return 0;
}