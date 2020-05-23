class Solution {
private:
	unordered_map<char, int> hashmap_t;
	unordered_map<char, int> hashmap_win;
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
		
		for(char c: t){
			hashmap_t[c]++;
		}

		int min_L = INT_MAX;
		string ans = "";
		int l = 0, r = 0;
		hashmap_win[s[0]] = 1;
		if(check()){
			min_L = 1;
			ans = s[0] + '\n';
			return ans;
		}

		while(r < s.size()){
			r++;
			if(hashmap_t.find(s[r]) != hashmap_t.end()){
				hashmap_win[s[r]]++;
			}
			while(check() && l <= r){
				if(r - l + 1 < min_L){
					min_L = r - l + 1;
					ans = s.substr(l, r-l+1);
				}

				if(hashmap_win.find(s[l]) != hashmap_win.end()){
					hashmap_win[s[l]]--;
				}
				l++;
			}
		}
		return ans;
    }

	bool check(){
		for(auto p: hashmap_t){
			if(hashmap_win[p.first] < p.second){
				return false;
			}
		}
		return true;
	}
};