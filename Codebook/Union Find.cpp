#include <bits/stdc++.h>]
using namespace std;

#define i64 long long
#define vi vector<int>
#define MAXN 1000001
#define lsb(x) (x)&(-(x))

vi ft;
int n;

vi father;

int find_(int u){
	if(u==father[u]) return u;
	return father[u] = find_(father[u]);
}

void union_(int u, int v){
	u = find_(u);
	v = find_(v);
	father[u] = v;
}


int main(){
	int n, k, u, v;
	string command;
	cin >> n >> k;
	father.assign(n+1,0);
	for(int i=1; i<=n; i++) father[i] = i;
	while(k--){
		cin >> command >> u >> v;
		if(command == "union") union_(u, v);
		else cout << (find_(u) == find_(v) ? "S" : "N") << endl;
	}
}