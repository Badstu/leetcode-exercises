#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string entityParser(string text) {
        map<string, string> hash = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"}
        };

        string key;
        string ans;
        for(auto c: text){
            if(c == '&'){
                if(!key.empty()){
                    ans += key;
                    key.clear();
                }
                key += c;
            } else if(c == ';'){
                key += c;
                if(hash.find(key) != hash.end()){
                    ans += hash[key];
                } else{
                    ans += key;
                }
                key.clear();
            } else{
                key += c; //都先加到key上面，碰到第一个&就判断key有没有值，有值就加到ans上
            }
        }
        if(!key.empty()){
            ans += key;
        }
        return ans;
    }
};
