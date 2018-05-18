#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


vector<int> scores;

int compare(int a, int b){
	return a > b;
}

int main(){
	int n, k, score, i;
	
	cin >> n >> k;
	
	for(i=n;i--;){
		cin >> score;
		scores.push_back(score);
	}

	sort(scores.begin(), scores.end(), compare);

	int ans = k;

	//for(i=0; i<k; i++);
	int last = scores[k-1]; i = k;

	while(scores[i] == last && i<n) ans++, i++;

	cout << ans << endl;
	return 0;
}
