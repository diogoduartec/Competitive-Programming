#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define MAX 100000
vi fat;

void makeFat(){
	int n = 1, ant = 1, val = 1;
	while(val <= MAX){
		fat.push_back(val);
		ant = val;
		n++;
		val = n*ant;
	}
}

int main(){
	makeFat();
	int ans = 0, n;
	cin >> n;
	for(int j=fat.size() - 1; j>=0; j--){
		while(fat[j] <= n){
			n-=fat[j];
			ans++;
		}
		if(n==0) break;
	}
	cout << ans << endl;
	return 0;
}