#include<bits/stdc++.h>

using namespace std;

// bool isconsist(string &a, string &b){
// 	if(a.size() == 0 || b.size() == 0){
// 		return a.size() == 0 && b.size() == 0;
// 	}

// 	if(a.size() % b.size() != 0){
// 		return false;
// 	}

// 	int l1 = a.size(), l2 = b.size();
// 	for(int i = 0; i < l1; i++){
// 		if(a[i] != b[i % l2]){
// 			return false;
// 		}
// 	}

// 	return true;
// }


// int main(){
// 	string s1, s2;
// 	string res;
// 	cin >> s1 >> s2;

// 	if(s1.size() < s2.size()){
// 		swap(s1, s2);
// 	}

// 	for(int l = s2.size(); l >= 1; l--){
// 		string x = s2.substr(0, l);
// 		if(isconsist(s1, x)){
// 			res = x;
// 			break;
// 		}
// 	}

// 	cout << res;
// 	return 0;
// }


int main(){
	string a, b;
	cin >> a >> b;
	int la = a.size(), lb = b.size();

	for(int i = min(la, lb); i >= 1; i--){
		if(la % i || lb % i) continue;
		if(a.substr(0, la - i) != a.substr(i, la - i) || b.substr(0, lb - i) != b.substr(i, lb - i)){
			continue;
		}
		if(a.substr(0, i) != b.substr(0, i)){
			continue;
		}
		cout << a.substr(0, i) << endl;
		return 0;
	}
	return 0;
}