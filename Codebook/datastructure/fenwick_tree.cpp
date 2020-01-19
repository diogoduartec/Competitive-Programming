//FENWICK TREE

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
	string command;
	int a, b;
	cin >> n;
	f3.assign(n+2,0);
	vi elements(n+2);
	for(int i=1; i<=n; i++){
		cin >> elements[i];
		update(i,elements[i]);
	}
	while(cin>>command>>a>>b){
		if(command=="query"){
			cout << query(b)-query(a-1) << endl;
		}
		else{
			update(a , (i64) b);
		}
	}
}