#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        if(n < 0) return -1;
        while(n > 0 && nums[n] == nums[0]) n--;
        if(nums[n] >= nums[0]) return nums[0]; // 完全单调的情况

        int l = 0, r = n;
        while(l < r){
            int mid = l + r >> 1; //[l, mid] [mid + 1, r]
            if(nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};
