//TSP - CAVALO

#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3
#define INFLL 0x3f3f3f3f3f3f3fLL
#define pos(i,j) ((i*m) + j)
#define posi(x) (x/m)
#define posj(x) (x%m)
#define ii pair<int, int >
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
#define ft first
#define sc second
#define vs vector<string>
#define eb emplace_back
#define FREE -1
#define BLOCK -2
#define VISITED 1
#define UNVISITED 0

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2}, dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
int n, m, k, board[102][102], adj[17][17];
vi pawns;

bool isValid(int x, int y){
	if(x<0 || x>=m || y<0 || y>=n || board[y][x] == BLOCK) return false;
	return true;
}

void bfs(int src){
	vi dist = vi(m*n + 2, INF); dist[src] = 0;
	vi vis = vi(m*n + 2, UNVISITED); vis[src] = VISITED;
	queue<int> q; q.push(src);
	int s = board[posi(src)][posj(src)];

	while(!q.empty()){
		int u=q.front(); q.pop();
		int i=posi(u), j=posj(u);

		if(board[i][j]>-1){
			adj[s][board[i][j]] = dist[u];
			//cout << s <<" - "<< board[i][j] <<" - "<< dist[u] <<" - "<< i << " - "<< j << endl;
		}

		for(int k=0; k<8; k++){
			int y = dy[k]+posi(u), x = dx[k]+posj(u);
			int v = pos(y,x);
			if(isValid(x, y) && !vis[v]){
				vis[v] = VISITED;
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
}

int memo[17][1<<17];

int tsp(int ant, int bitmask){
	if(bitmask == (1<<(k+1)) - 1) return adj[ant][0];
	if(memo[ant][bitmask] != -1) return memo[ant][bitmask];

	int ans = INF;
	for(int i=0; i<=k; i++){
		if(!(bitmask & (1<<i))){
			ans = min(ans, tsp(i, (bitmask | (1<<i))) + adj[ant][i]);
		}
	}

	return memo[ant][bitmask] = ans;

}

int main(){
	char c;
	while((cin >> n >> m >> k) && (n+m+k)){
		int id = 1;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> c;
				if(c == '.') board[i][j] = FREE;
				else if(c == '#') board[i][j] = BLOCK;
				else if(c == 'P'){
					board[i][j] = id++;
					pawns.eb(pos(i,j));
				}
				else if(c == 'C'){
					board[i][j] = 0;
					pawns.insert(pawns.begin(), pos(i,j));
				}
			}
		}

		for(auto v: pawns) bfs(v);
		// for(int i=0; i<pawns.size(); i++){
		// 	for(int j=0; j<pawns.size(); j++) cout << i <<" - "<<j<<" - "<< "adj[i][j]: " << adj[i][j] << endl;
		// 	cout << endl;
		// }
		// cout << "-----------------------" << endl;
		
		memset(memo, -1, sizeof(memo));
		cout << tsp(0, 1) << endl;
		pawns.clear();

	}

	return 0;
}
