#include<bits/stdc++.h>

using namespace std;

int main(){
	string str;
	string dicts;

	vector<string> dd;

	getline(cin, str);
	getline(cin, dicts);

	int i = 0;
	while(i < dicts.size()){
		int k = i;
		while(k < dicts.size() && dicts[k] != ' '){
			k++;
		}
		dd.push_back(dicts.substr(i, k - i));
		i = k + 1;
	}

	string temp_str = "";
	for(int j = 0; j < str.size(); j++){
		if(str[j] == ' ') continue;
		temp_str += str[j];
	}

	for(int j = 0; j < temp_str.size(); j++){
		for(string pattern: dd){
			int k = j + pattern.size() - 1;
			if(k >= temp_str.size()) continue;

			string src = temp_str.substr(j, pattern.size());
			if(src == pattern){
				
				j = k;
			}
		}
	}

	cout << temp_str << endl;



	return 0;
}
