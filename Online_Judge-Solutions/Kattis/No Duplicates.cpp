#include <bits/stdc++.h>
using namespace std;

int main(){
	set<string> text;
	string input;
	bool flag = true;
	while(cin>>input){
		if(text.count(input)) flag = false;
		else text.insert(input);
	}
	if(flag) cout << "yes" << endl;
	else cout << "no" << endl;
}