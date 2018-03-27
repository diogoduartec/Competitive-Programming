/*
* create by Diogo Duarte on 26/03/2018
* Fenwick Tree implementation
*/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define i64 long long
#define lsb(x) (x)&(-(x))

vi f3;
int n;

void update(int idx, i64 val){
	while(idx<=n){
		f3[idx]+=val;
		idx += lsb(idx);
	}
}

i64 query(int idx){
	i64 result = 0LL;
	while(idx>0){
		result += f3[idx];
		idx -= lsb(idx);
	}
	return result;
}

int main(){
	int player;
	while(cin>>n){
		f3.assign(n+1,0);
		vi players(n+1);
		for(int i=n; i>=1; i--){
			cin >> player;
			players[player] = i;
			update(i,1LL);
		}
		i64 ans = 0LL;
		for(int i=1; i<=n; i++){
			ans += query(players[i]-1);
			update(players[i], -1LL);
		}
		cout << ans << endl;
	}
}