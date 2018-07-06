#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 123
#define _ ios_base::sync_with_stdio(0);

int main(){_
	int adj[MAXN][MAXN];
	int n, m, v, u, d, query, inst=1;

	while((cin >> n >> m) && m+n){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++)
				adj[i][j] = INF;
		}

		while(m--){
			cin >> u >> v >> d;
			adj[v][u] = d;
			adj[u][v] = d;
		}
		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++)
					adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
			}
		}
		for (int k=1;k<=n;k++) adj[k][k]=0;
		
		cin >> query;
		cout << "Instancia " << inst++ << endl;
		while(query--){
			cin >> u >> v;
			cout << adj[u][v] <<endl;
		}
		cout << endl;
	}
	return 0;
}
