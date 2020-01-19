// (LIS) LONGEST INCREASING SUBSEQUENCE

#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define ii pair<int,int >
#define MAXN 100005

int memo[MAXN], a[MAXN];
int n, k;

int f(){

	for(int i=n; i>=1; i--){
		memo[i] = 1;
		for(int j=i+1; j<=n; j++){
			if(a[j] > a[i] && 1+memo[j] > memo[i]){
				memo[i] = 1 + memo[j];
			}
		}
	}
	
	int ans = 0;
	for(int i=1; i<=n; i++) ans=max(ans, memo[i]);
	return ans;
}

int main(){
	int x;
	while(cin >> n){
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}
		cout << f() << endl;
	}	

	return 0;
}
