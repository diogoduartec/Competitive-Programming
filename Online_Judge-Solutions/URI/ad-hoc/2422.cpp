#include <bits/stdc++.h>
using namespace std;
#define MAX 100100
int k, vet[MAX], lo, hi, mid, n;
void binary_search(int pos){
	lo = pos+1;
	hi = n;
	while(lo<hi){
		mid = lo + (hi-lo)/2;
		if(vet[mid]+vet[pos]>=k) hi = mid;
		else lo = mid+1;
	}
}

int main(int argc, char** argv)
{
	cin >> n;
	for(int i=0; i<n; i++) cin >> vet[i];
	cin >> k;
	for(int i=0; i<n; i++){
		binary_search(i);
		if(vet[lo]+vet[i]==k){
			cout << vet[i] << " " << vet[lo] << endl;
			break;
		}
	}
	return 0;
}