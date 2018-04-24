#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi parent;

int find(int u){
	return (parent[u]==u ? u : parent[u] = find(parent[u]));
}

void union_(int u, int v){
	parent[find(u)] = find(v);
}

int main(){
	int t, n, m, x, y;
	cin >> t;
	for(int case_=1; case_<=t; case_++){
		cin >> n >> m;
		int count=0;
		for(int i=0; i<=n; i++) parent.push_back(i);
		while(m--){
			cin >> x >> y;
			if(find(x)!=find(y)){
				union_(x, y);
				count++;
			}
		}
		int ans = n - 1 - count;
		cout << "Caso #"<<case_<<": ";
		if(ans==0) cout <<"a promessa foi cumprida"<< endl;
		else cout <<"ainda falta(m) "<<ans<<" estrada(s)"<<endl;
		parent.clear();
	}
	return 0;
}