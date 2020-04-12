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
                string s = words[j], p = words[i];
                int len_i = p.size(), len_j = s.size();
                if(len_i >= len_j || set.count(p)) continue;

                if(s.find(p) != string::npos){
                    res.push_back(p);
                    set.insert(p);
                    break;
                }
                // for(int k = 0; k < len_j; k++){
                //     if(s.substr(k, len_i) == p && !set.count(p)){
                //         res.push_back(p);
                //         set.insert(p);
                //         break;
                //     }
                // }
            }
        }
        return res;
    }
};