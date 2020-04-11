#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> hash = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    int n;

    vector<string> letterCombinations(string digits) {
        n = digits.size();
        string path;
        dfs(0, path, digits);

        return res;
    }

    void dfs(int depth, string &path, string &digits){
        if(depth >= n){
            res.push_back(path);
            return;
        }

        for(auto c: hash[digits[depth] - '0']){
            path += c;
            dfs(depth + 1, path, digits);
            path.erase(depth, 1);
        }

        return;
    }

};


int main(){
    Solution su = Solution();
    auto v = su.letterCombinations("23");
    for(auto i: v) cout << i << " ";

    return 0;
}