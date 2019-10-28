/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *  输入: "babad"
    输出: "bab"
    注意: "aba" 也是一个有效答案。
 */

// @lc code=start
#include<iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;



class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0)
            return "";
        string result;
        result.push_back(s[0]);
        int len = s.size();
        int P[len][len];
        memset(P, 0, sizeof(P));
        
        for(int i = 0; i < len; ++i){
            P[i][i] = 1;
            if(i < len - 1){
                if (s[i] == s[i+1]){
                    P[i][i + 1] = 1;
                    result = s.substr(i, 2);
                }
            }
        }

        for(int gap = 2; gap < len; ++gap){
            for (int i = 0; i < len - gap; ++i){
                int j = i + gap;
                if(s[i]==s[j]){
                    P[i][j] = P[i + 1][j - 1];
                    // cout << i << j << " ";
                    // cout << s.substr(i, j - i + 1) << " " << P[i][j] << endl;
                    if(P[i][j] && gap+1 > result.size()){
                        result = s.substr(i, gap+1);
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

