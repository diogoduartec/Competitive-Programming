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

void update(int startIdx, int endIdx, i64 val){
	while(startIdx<=endIdx){
		f3[startIdx]+=val;
		cout << startIdx <<"  ";
		startIdx += lsb(startIdx);
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
	int t, u, l, r, q, idx;
	i64 val;
	cin >> t;
	while(t--){
		cin >> n >> u;
		f3.assign(n+1, 0);
		while(u--){
			cin >> l >> r >> val;
			update(l+1,r+1,val);
			cout << endl << endl;
			/*for(int i=1; i<=n; i++)
				cout <<i<<"---"<< query(i) <<endl;
			cout << "\n-----------------------------\n";*/
		}
		/*for(int i=1; i<=n; i++)
			cout <<i<<"---"<< query(i) <<endl;*/
		cin >> q;
		while(q--){
			cin >> idx;
			cout << query(idx+1) << endl;
		}
	}
}