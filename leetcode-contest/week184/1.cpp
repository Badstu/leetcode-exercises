#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        unordered_set<string> set;

        int n = words.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int len_i = words[i].size(), len_j = words[j].size();
                if(len_i >= len_j) continue;
                
                string s = words[j], p = words[i];
                for(int k = 0; k < len_j; k++){
                    if(s.substr(k, len_i) == p && !set.count(p)){
                        res.push_back(p);
                        set.insert(p);
                        break;
                    }
                }
            }
        }
        return res;
    }
};