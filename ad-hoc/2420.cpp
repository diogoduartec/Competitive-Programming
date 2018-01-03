#include <bits/stdc++.h>
using namespace std;
#define MAX 100100
int vet[MAX], lo, hi, mid, n;
int sum(int k){
	int sum1=0, sum2=0;
	for(int i=0; i<=k; i++) sum1+=vet[i];
	for(int i=k+1; i<n; i++) sum2+=vet[i];
	if(sum1==sum2) return 0;
	if(sum1>sum2) return 1;
	return -1;
}

int main(int argc, char** argv)
{
	cin >> n;
	for(int i=0; i<n; i++) cin >> vet[i];
	lo=0;
	hi=n;
		while(lo<hi){
			mid = lo+(hi-lo)/2;
			int s = sum(mid);
			if(s==0){
				cout << mid+1 << endl;
				break;
			}
			else if(s==1) hi = mid;
			else lo = mid+1;
		}
	return 0;
}