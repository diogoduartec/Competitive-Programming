#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define INF 0x3f3f3f3f
#define MAXM 100005

int c, s, a, b, c1, c2;
vii adj_list[MAXM];

int dijkstra(int src, int dest){
	vi dist(c+1, INF); dist[src] = 0;
	priority_queue<ii, vii, greater<ii> > pq; pq.push({0, src});
	while(!pq.empty()){
		int w = pq.top().first, u = pq.top().second; pq.pop();
		if(u == dest) return dist[u];
		if(w > dist[u]) continue;
		for(int i=0; i<adj_list[u].size(); i++){
			int d = adj_list[u][i].first, v = adj_list[u][i].second;
			if(d+w<dist[v]){
				dist[v] = d+w;
				pq.push({d+w, v});
			}
		}
	}
	return dist[dest];
}

int main(){
	//vii adj_a[MAXM], adj_b[MAXM];
	
	cin >> c >> s >> a >> b;
	
	while(s--){
		cin >> c1 >> c2;
		adj_list[c1].push_back({0, c2});
		adj_list[c2].push_back({1, c1});
	}

	int bibi = dijkstra(a, b);
	int bibika = dijkstra(b, a);
	if(bibi < bibika) cout << "Bibi: " <<bibi<<endl;
	else if(bibika < bibi) cout << "Bibika: " <<bibika<< endl;
	else cout << "Bibibibika" << endl;

	return 0;
}