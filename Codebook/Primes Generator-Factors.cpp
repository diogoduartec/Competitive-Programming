#include <bits/stdc++.h>
#define i64 long long
#define vi64 vector<i64>
using namespace std;

bitset<1000005> bs;
vi64 primes;
bool isDespojado = true;

void makePrimes(i64 upperbound){//create list of primes in [0..upperbound]
	bs.set();
	bs[0] = bs[1] = 0;
	for(i64 i=2; i<=upperbound; i++) if(bs[i]){
		/*cross out multiples of i starting from i*i*/
		for(i64 j = i*i; j<=upperbound; j+=i) bs[j]=0;
		primes.push_back(i);
	}
}

vi64 primeFactors(i64 n){
	makePrimes(ceil((i64)sqrt(n)));
	vi64 factors;
	if(primes.size()==0) factors;
	i64 pf_idx = 0, pf = primes[0];
	while(pf*pf <= n){
		int cont = 0;
		while(n%pf == 0){
			n/=pf;
			factors.push_back(pf);
		}
		if(pf_idx >= primes.size()-1) break;
		pf = primes[++pf_idx];
	}
	if(n!=1) factors.push_back(n);//special case if n is a prime
	return factors;
}

int main(){
	i64 n;
	while(cin >> n){
		vi64 ans = primeFactors(n);
		for(i64 i = 0; i<ans.size(); i++) cout << ans[i] << " ";
		cout << endl;
	}
}