#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define vi vector<i64>
#define lsb(x) (x)&(-(x))
vi ft;
int n=100005;

void update(int idx, i64 val){
	while(idx<=n){
		ft[idx]+=val;
		idx+=lsb(idx);
	}
}

i64 query(int idx){
	i64 result = 0LL;
	while(idx>=1){
		result+=ft[idx];
		idx-=lsb(idx);
	}
	return result;
}

int main(){
	int ip, m, pc, na;
	while(cin>>ip>>m){
		ft.assign(100005, 0LL);
		int ans = 0;
		while(m--){
			cin >> pc >> na;
			int q1 = min(100000, pc+ip);
			int q2 = max(1,pc-ip);
			if((query(q1) - query(q2-1)) <= na){
				ans++;
				update(pc,1LL);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
