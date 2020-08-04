# include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hash_map;

        for(int i = 0; i < nums.size(); i++){
            int t = target - nums[i];

            if(hash_map.find(t) != hash_map.end()){
                res = {i, hash_map[t]};
            }

            hash_map[nums[i]] = i;
        }
        return res;
    }
};
// @lc code=end

