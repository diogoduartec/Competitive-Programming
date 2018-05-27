#include <bits/stdc++.h>
using namespace std;

#define MAXN 10005
#define MAXM 100005
#define i64 long long

struct Edge{
	int u, v, w;
};

int n, m, parent[MAXN];
Edge edges[MAXM];

int compare1(Edge a, Edge b){
	return a.w < b.w;
}

int compare2(Edge a, Edge b){
	return a.w > b.w;
}

void init(int n){
	for(int i=0; i<=n; i++) parent[i] = i;
}

int id(int v){
	return(parent[v] == v ? v : parent[v]=id(parent[v]));
}

void join(int u, int v){
	parent[id(u)] = id(v);
}


i64 kruskal(){
	i64 ans = 0;
	init(n);
	for(int i=0; i<m; i++){
		Edge e = edges[i];
		if(id(e.u)!=id(e.v)){
			join(e.u, e.v);
			ans+=e.w;
		}
	}
	return ans;
}


int main(){
	i64 total;
	while((cin>>n>>m)&&n+m){
		for(int i=0; i<m; i++){
			cin >> edges[i].u >> edges[i].v >> edges[i].w;
		}
		sort(edges, edges + m, compare2);
		i64 maximum = kruskal();
		sort(edges, edges + m, compare1);
		i64 minimum = kruskal();
		cout << maximum - minimum << endl;
	}
}