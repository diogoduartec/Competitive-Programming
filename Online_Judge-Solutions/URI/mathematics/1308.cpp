#include <bits/stdc++.h>
using namespace std;

unsigned long long int f(unsigned long long int n){
	return (n*(n+1))/2;
}

int main(int argc, char** argv)
{
	unsigned long long int casos, n, mid, lo, hi;
	cin >> casos;
	while(casos--)
	{
		cin >> n;
		lo = 0;
		hi = 2*sqrt(n);
		while(lo < hi){
			mid = lo + (hi-lo)/2;
			if(f(mid)>=n) hi = mid;
			else lo = mid+1;
		}
	if(f(lo)==n)
		cout << lo << endl;
	else cout << lo-1 << endl;
	}	
	return 0;
}