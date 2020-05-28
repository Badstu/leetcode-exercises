class Solution {
public:
    string decodeString(string s) {
		vector<string> stk;
		for (int i = 0; i < s.length(); i++){
			string t = "";
			while(isDigit(s[i])){
				t += s[i];
				i++;
			}
			if(t != "") stk.push_back(t);
			
			if(isalpha(s[i]) || s[i] == "["){
				stk.push_back(string(1, s[i]));
			} else {
				vector<string> sub;
				while(stk.back() != "["){
					sub.push_back(stk.back());
					stk.pop_back();
				}
				reverse(sub.begin(), sub.end());
				stk.pop_back();
				int t = stoi(stk.back());
				stk.pop_back();
				string sub_string, temp_string;
				for(auto s: sub){
					temp_string += s;
				}
				while(t--){
					sub_string += temp_string;
				}
				stk.push_back(sub_string);
			}
		}
		string res;
		for(auto s: stk){
			res += s;
		}
		return res;
    }

};