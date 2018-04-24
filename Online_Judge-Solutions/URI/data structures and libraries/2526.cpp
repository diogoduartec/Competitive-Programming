#include <bits/stdc++.h>]
using namespace std;

#define i64 long long
#define vi vector<i64>
#define MAXN 1000001
#define lsb(x) (x)&(-(x))

vi ft;
int n;

void update(int idx, i64 val){
	for(;idx<=n; idx+=lsb(idx)){
		ft[idx]+=val;
	}
}

i64 query(int idx){
	i64 ans = 0LL;
	for(;idx>=1;idx-=lsb(idx))
		ans+=ft[idx];
	return ans;
}

int main(){
	int x;
	while(cin >> n){
		vi smaller(n+1), bigger(n+1), menu(n+1);
		
		for(int i=1; i<=n; i++) cin >> menu[i];


		ft.assign(n+1, 0LL);
		for(int i=1; i<=n; i++){
			bigger[i] = i - query(menu[i]);//maiores
			update(menu[i], 1LL);
		}

		ft.assign(n+1, 0LL);
		for(int i=n; i>=1; i--){
			smaller[i] = query(menu[i]);//menores
			update(menu[i], 1LL);
		}
		reverse(smaller.begin(), smaller.end());

		i64 ans = 0LL;
		for(int i=1; i<=n; i++)
			ans += smaller[i] * bigger[j];

		cout << ans << endl;
	}
}