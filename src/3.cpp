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
        int length = 0, max_length = 0;
        int start = 0, end = 0;
        bool isContinue = false;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c == s[i-1]){
                isContinue = true;

            }
            cout << i << c << hashmap[c] << endl;
            if(hashmap[c] != 0){
                // i = start++;
                // end = start + 1;
                hashmap[c] = 0;
            } else {
                end++;
                hashmap[c]++;
            }
            cout << start << " " << end << endl;
            
            length = end - start;
            if (length > max_length) {
                max_length = length;
            }
        }
        cout << max_length;

        return max_length;
    }
};
// @lc code=end

