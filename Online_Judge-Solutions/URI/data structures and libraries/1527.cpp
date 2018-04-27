#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int >
#define i64 long long
#define vii vector<pair>
#define vi vector<int>
#define vi64 vector<i64>
#define pb push_back
#define ft first
#define sc second

vi parent;
vi64 power;

void init(int n){
	i64 x;
	parent.clear();
	power.clear();
	power.pb(-1000LL);
	for(int i=0; i<=n; i++) parent.pb(i);
	for(int i=1; i<=n; i++){
		cin >> x;
		power.pb(x);
	}
}

int find(int v){
	return (parent[v]==v ? v : parent[v]=find(parent[v]));
}

void union_(int v, int u){
	if(find(v) != find(u)){
		power[find(u)] += power[find(v)];
		parent[find(v)] = find(u);
	}
}

int getRaphael(int a, int b){
	if(find(a) == find(1)) return a;
	if(find(b) == find(1)) return b;
	return 0;
}

int getOponent(int a, int b, int idRaphael){
	if(idRaphael == a) return b;
	return a;
}

int main(){
	int n, m, a, b, q;
	while((cin>>n>>m) && n+m){
		init(n);
		int ans = 0;
		while(m--){
			cin >> q >> a >> b;
			if(q==1) union_(a,b);
			else{
				int idRaphael = getRaphael(a,b);
				if(power[find(idRaphael)] > power[find(getOponent(a,b,idRaphael))]) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
