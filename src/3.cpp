/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> hashmap;
        int max_length = 0;
        int start = 0, end = 0;
        hashmap[s[start]] = 1;

        while(s[end] != 0){
            max_length = max_length > (end - start + 1) ? max_length : (end - start + 1);
            ++end;
            // cout << end << " " << s[end] << " " << hashmap[s[end]] << endl;
            while(0 != hashmap[s[end]]){
                hashmap[s[start]] = 0;
                ++start;
            }
            hashmap[s[end]] = 1;
        }
        return max_length;
    }
};
// @lc code=end

