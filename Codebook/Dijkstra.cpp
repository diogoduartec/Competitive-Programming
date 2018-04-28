#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define i64 long long
#define ii pair<i64, int >
#define vii vector<ii>
#define vi vector<int>
#define MAXN 10000

vii adj[MAXN];
vi dist;
int n, m;
void dijkstra(int src, int dest){
	dist.assign(n+1, INF); dist[src] = 0;
	priority_queue<ii, vii, greater<ii> > pq; pq.push({0LL, src});
	while(!pq.empty()){
		i64 w = pq.top().first; int v = pq.top().second; pq.pop();
		if(v==dest) return;
		if(w>dist[v]) continue;
		for(int i=0; i<adj[v].size(); i++){
			i64 d = adj[v][i].second; int u = adj[v][i].first;
			if(dist[u]>d+w){
				dist[u] = d+w;
				pq.push({d+w, u});
			}
		}
	}
}

int main(){
	int v, u, scr, dest;
	i64 w;
	while((cin>>n>>m)&&(n||m)){
		while(m--){
			cin >> v >> u >> w;
			adj[v].push_back(ii{u,w});
		}
		cin >> scr >> dest;
		dijkstra(scr, dest);
		if(dist[dest]==INF) cout << "-1" << endl;
		else cout <<dist[dest]<< endl;
		for(int i=0; i<=n; i++) adj[i].clear();
	}
	return 0;
}