#include <bits/stdc++.h>
#define i64 long long
#define vi64 vector<i64>
using namespace std;

bitset<1000000000001> bs;
vi64 primes;

void makePrimes(i64 upperbound){//create list of primes in [0..upperbound]
	bs.set();
	bs[0] = bs[1] = 0;
	for(i64 i=2; i<=upperbound; i++) if(bs[i]){
		/*cross out multiples of i starting from i*i*/
		for(i64 j = i*i; j<=upperbound; j+=i) bs[j]=0;
		primes.push_back(i);
	}
}

int main(){
	makePrimes(100000);
	cout << primes.size()<< endl;
	for(int i=0; i<primes.size(); i++) cout << primes[i] << " ";
	cout << endl;
}