#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        
        int max_length = 0;
        int res_i = 0, res_j = 0;
        for(int l = 1; l <= n; l++){
            for(int i = 0; i < n; i++){
                int j = i + l - 1;
                if(j >= n) continue;

                if(l == 1){
                    dp[i][j] = true;
                } else if(l == 2){
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                }

                if(dp[i][j] && l > max_length){
                    max_length = l;
                    res_i = i;
                    res_j = j;
                }
            }
        }
        
        return s.substr(res_i, res_j - res_i + 1);
    }
};
// @lc code=end

