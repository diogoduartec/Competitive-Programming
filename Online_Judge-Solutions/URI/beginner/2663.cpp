#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


vector<int> scores;

int main(){
	int n, k, score, i;
	
	cin >> n >> k;
	
	for(i=n;i--;){
		cin >> score;
		scores.push_back(score);
	}

	sort(scores.begin(), scores.end());

	int ans = k;
	int last = scores[k-1]; i = k;

	while(scores[i] == last && i<n) ans++, i++;

	cout << ans << endl;
	return 0;
}