#include <bits/stdc++.h>
using namespace std;

#define MAXN 505
#define MAXM 255025
#define ii pair<int, int >
#define vii vector<ii>
#define vi vector<int>
#define pb push_back
#define ft first
#define sc second


typedef struct{
	int u, v;
	double w;
}Edge;

int n, m, parent[MAXN];
vector<Edge> edges;
vii coordinates;


void makeEdges(){
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			double w = hypot(abs(coordinates[i].ft - coordinates[j].ft), abs(coordinates[i].sc - coordinates[j].sc));
			Edge edge;
			edge.u = i; edge.v = j; edge.w = w;
			edges.pb(edge);
		}
	}
}

void init(){
	for(int i=0; i<=n; i++) parent[i] = i;
}

int compare(Edge a, Edge b){
	return a.w < b.w;
}

int id(int u){
	return(parent[u]==u ? u : parent[u] = id(parent[u]));
}

void join(int u, int v){
	parent[id(u)] = id(v);
}

double kruskal(){
	double ans = 0.0;
	makeEdges();
	init();
	sort(edges.begin(), edges.end(), compare);
	for(int i=0; i<edges.size(); i++){
		Edge e = edges[i];
		if(id(e.u) != id(e.v)){
			join(e.u, e.v);
			ans += e.w;
		}
	}
	return ans;
}

int main(){
	cout << fixed << setprecision(2);
	int c, x, y;
	
	while(cin >> n){
		coordinates.clear();
		edges.clear();
		for(int i=0; i<n; i++){
			cin >> x >> y;
			coordinates.pb({x,y});
		}
		cout << kruskal() << endl;
	}
	return 0;
}