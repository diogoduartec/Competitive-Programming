#include <bits/stdc++.h>
using namespace std;

#define MAXN 1234

int cbd[MAXN][MAXN];

int main(){
	int p, n, c, ac;
	while((cin>>p>>n>>c)&&p+n+c){

		for(int i=0; i<n; i++){
			for(int j=0; j<p; j++){
				cin >> cbd[i][j];
			}
		}
		int ans = 0;
		for(int j=0; j<p; j++){
			ac = 0;
			for(int i=0; i<n; i++){
				if(cbd[i][j]) ac++;
				if((!cbd[i][j]) || i==n-1){
					if(ac>=c){
						ans++;
					}
					ac = 0;
				}
			}
		}
		cout << ans << endl;
	}
}