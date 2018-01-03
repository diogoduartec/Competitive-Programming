#include<bits/stdc++.h>
#define MAX 10001
using namespace std;

int vet[MAX];

int main(){
	int n, q, mid, ri, lo, c;

	int cont = 1;
	while((cin>>n>>q)&&(n||q)){
		for(int i=0; i<n; i++){
			cin >> vet[i];
		}
		sort(vet, vet+n);
		printf("CASE# %d:\n", cont++);
		while(q--){
			cin >> c;
			lo = 0;
			ri = n-1;
			while(lo<ri){
				mid = lo + (ri-lo)/2;
				if(vet[mid]>=c){
					ri = mid;
				}
				else lo = mid+1;
			}
			if(vet[lo]==c)
				printf("%d found at %d\n", c, lo+1);
			else  printf("%d not found\n", c);
		}
	}
	return 0;
}