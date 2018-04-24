#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi parent;

int find(int v){
	return(parent[v]==v ? v : parent[v] = find(parent[v]));
}

void union_(int u, int v){
	parent[find(u)] = find(v);
}

int main(){
	int e, l, x, y, test=1;
	while((cin>>e>>l)&&e+l){
		for(int i=0; i<=e; i++) parent.push_back(i);
		int count=0;
		while(l--){
			cin >> x >> y;
			if(find(x)!=find(y)){
				count++;
				union_(x, y);
			}
		}
		int ans = e - count - 1;
		cout << "Teste "<<test++ << endl;
		cout <<(ans==0 ? "normal" : "falha")<<endl<<endl;
		parent.clear();
	}
}