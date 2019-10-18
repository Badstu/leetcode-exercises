/*
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

*/
#include<iostream>
#include<vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int temp_sum = 0;
        vector<int> result_index;
        int ox = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++){
                temp_sum = nums[i] + nums[j];
                // cout << i << " " << j << endl;
                if (temp_sum == target){
                    result_index.push_back(i);
                    result_index.push_back(j);
                    // cout << i << j;
                    ox = 1;
                    break;
                }
            }
            if(ox == 1){
                break;
            }
        }
        return result_index;
    }
};

class Solution2{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<char, int> hashmap;
        hashmap['a'] = 1;
        vector<int> result_index;
        // for(int i = 0; i < nums.size(); i++){
        //     int value = nums[i];
        //     if (value > target){
        //         continue;
        //     } else {
        //         int another_value = target - value;
        //         // cout << another_value << endl;
        //         if (hashmap.find(another_value) != hashmap.end()){
        //             result_index.push_back(hashmap[another_value]);
        //             result_index.push_back(i);
        //             cout << hashmap[another_value] << " " << i << endl;
        //             break;
        //         }
        //     }
        //     hashmap[value] = i;
        // }
        return result_index;
    }
};