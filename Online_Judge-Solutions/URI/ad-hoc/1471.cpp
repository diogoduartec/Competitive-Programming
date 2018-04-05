#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, x;
	while(cin >> n >> n){
		vector<int> merg(n+1,0);
		while(m--){
			cin >> x;
			merg[x] = 1;
		}
		int count = 0;
		for(int i=1; i<=n; i++){
			if(!merg[i]){
				if(count) cout << " ";
				cout << i;
			}
		}
		if(!count) "*";
		cout << endl;
	}
}