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

using namespace std;



class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        int length = 0, maxlength = 0;
        vector<char> stack1;
        for (int i = 0; i <= s.size(); ++i){
            stack1.push_back(s[i]);
            
        }
        

        return result;
    }
};
// @lc code=end

