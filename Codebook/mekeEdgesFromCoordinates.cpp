//CONSTROI ARESTAS A PARTIR DE COORDENADAS

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int >
#define vii vector<ii>
#define pb push_back
#define ft first
#define sc second

typedef struct{
	int u, v;
	double w;
}Edge;

int n;
vii coordinates;
vector<Edge> edges;

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

int main(){
	cout << fixed << setprecision(2);
	int x, y;
	cin >> n;
	for(int i=n;i--;){
		cin >> x >> y;
		coordinates.push_back({x,y});
	}
	makeEdges();
	for(int i=0; i<edges.size(); i++){
		cout << edges[i].u << " " << edges[i].v << " " << edges[i].w << endl;
	}
}