/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int length = 0;
        unordered_map<char, int> hash_map;

        for(int i = 0, j = -1; i < n; i++){
            while(j+1 < n && (hash_map.find(s[j + 1]) == hash_map.end() || hash_map[s[j+1]] == 0)){
                j++;
                hash_map[s[j]] += 1;
            }
            length = max(length, j - i + 1);

            hash_map[s[i]] --;
        }

        return length;
    }
};
// @lc code=end

