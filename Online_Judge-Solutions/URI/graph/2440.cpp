#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi father;
set<int> kin;


int find_(int u){
	return ((father[u]==u) ? u : (father[u] = find_(father[u])));
}

void union_(int u, int v){
	father[find_(u)] = find_(v);
}

int main(){
	int n, m, u, v;
	cin >> n >> m;

	father.assign(n+1,0);

	for(int i=1; i<=n; i++) father[i] = i;
	
	while(m--){
		cin >> u >> v;
		union_(u, v);
	}	
	for(int i=1; i<=n; i++){
		kin.insert(find_(i));
	}
	cout << kin.size() << endl;
}