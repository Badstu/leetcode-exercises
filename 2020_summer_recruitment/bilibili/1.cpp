#include <bits/stdc++.h>

using namespace std;

string s1, s2;
unordered_map<char, int> count1, count2;

int main(){
	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();

	if(n == 0){
		if(m == 0){
			cout << 1 << endl;
		} else cout << 0 << endl;
		return 0;
	}

	if(n != m){
		cout << 0 << endl;
		return 0;
	}

	for(int i = 0; i < n; i++){
		count1[s1[i]] ++;
		count2[s2[i]] ++;
	}

	if(count1.size() != count2.size()){
		cout << 0 << endl;
		return 0;
	}

	for(auto t: count1){
		char k = t.first;
		if(count2.find(k) == count2.end() || count1[k] != count2[k]){
			cout << 0 << endl;
			return 0;
		}
	}

	cout << 1 << endl;


	return 0;
}