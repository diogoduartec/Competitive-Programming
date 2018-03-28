/*
* create by Diogo Duarte on 28/03/2018
* Problem: Update the array ! (UPDATEIT)
* OJ: Spoj
* # Fenwick Tree
*/
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define i64 long long
#define lsb(x) (x)&(-(x))
#define _ ios_base::sync_with_stdio(0);

vi f3;
int n;

void update(int startIdx, int endIdx, i64 val){
	while(startIdx<=n){
		f3[startIdx]+=val;
		startIdx += lsb(startIdx);
	}
	while(endIdx<=n){
		f3[endIdx] -= val;
		endIdx += lsb(endIdx);
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

int main(){_
	int t, u, l, r, q, idx;
	i64 val;
	cin >> t;
	
	while(t--){
		cin >> n >> u;
		f3.assign(n+1, 0);
		
		while(u--){
			cin >> l >> r >> val;
			update(l+1,r+2,val);
		}

		cin >> q;
		
		while(q--){
			cin >> idx;
			cout << query(idx+1) << endl;
		}
	}
}