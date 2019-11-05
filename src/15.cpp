/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
        cout << "success" << endl;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size() - 1;

            if(left >= right) break;

            while(left < right){
                int value = nums[left] + nums[right] + nums[i];
                if(value < 0){
                    left++;
                } else if (value > 0){
                    right--;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[++left]);
                    while(left < right && nums[right] == nums[--right]);
                }
            }
            
        }
        cout << "=============" << endl;
        if(result.size() != 0){
            for(int i = 0; i < result.size(); i++){
                for(int j = 0; j < result[0].size(); j++){
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
        }


        return result;
    }
};
// @lc code=end

