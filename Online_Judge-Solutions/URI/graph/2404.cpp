#include <bits/stdc++.h>
using namespace std;

#define MAXN 505
#define MAXM 124755

struct Edge{
	int u, v, w;
};


int n, m, u, v, w, parent[MAXN];
Edge edges[MAXM];

int compare(Edge a, Edge b){
	return a.w < b.w;
}

void init(int n){
	for(int i=0; i<=n; i++) parent[i] = i;
}

int find(int v){
	return (parent[v]==v ? v : parent[v] = find(parent[v]));
}

void union_(int u, int v){
	parent[find(v)] = find(u);
}

int kruskal(){
	int ans = 0, u, v, w;
	init(n);
	sort(edges, edges + m, compare);
	for(int i=0; i<m; i++){
		Edge e = edges[i];
		u = e.u, v = e.v, w = e.w;
		if(find(u) != find(v)){
			union_(u,v);
			ans +=w ;
		}
	}
	return ans;
}

int main(){
	while(cin>>n>>m){
		for(int i=0; i<m; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
		cout << kruskal() << endl;
	}
	return 0;
}
