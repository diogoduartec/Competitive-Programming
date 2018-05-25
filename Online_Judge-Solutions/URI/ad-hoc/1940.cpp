#include <bits/stdc++.h>
using namespace std;


int main(){
    
	int j, r, score;
	vector<int> scores;

	cin >> j >> r;
	
	scores.assign(j+2, 0);
	int n = j*r;
	while(r--){
		for(int i=1; i<=j; i++){
		    cin >> score;
		    scores[i] += score;
		}
	}
	int ans = 0, maxi = 0;
	for(int i=1; i<=j; i++){
	    if(scores[i] >= maxi){
	        maxi = scores[i];
	        ans = i;
	    }
	}
	cout <<ans<< endl;
	
	return 0;
}
