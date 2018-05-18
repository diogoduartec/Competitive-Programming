#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define ft first
#define sc second
#define _ ios_base::sync_with_stdio(0);

unordered_map<int, int> men, women;
int n, m, k;

//h k
//3 7 = 4
//7 3 = 2

int firstPossibility(int hight){
	if(hight>k){
		return (((hight/k)+1)*k) - hight;
	}
	else{
		return k - hight;
	}
}

int main(){_
	int manHight, womanHight;

	while(cin >> n >> m >> k){
		int maxManHight = 0, maxWomanHight=0, minManHight;
		int ans = 0;
		
		while(n--){
			cin >> manHight;
			men[manHight]++;
			maxManHight = max(maxManHight, manHight);
		}
		
		while(m--){
			cin >> womanHight;
			for(int id=firstPossibility(womanHight); id<=maxManHight; id+=k){
				ans+=men[id];
			}
		}
		
		cout << ans << endl;
		men.clear(); women.clear();
	}
	return 0;
}