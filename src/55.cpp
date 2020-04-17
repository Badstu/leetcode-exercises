class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return true;
        int max_i = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i > max_i) return false;
            if(max_i < nums[i] + i) max_i = nums[i] + i;
            if(max_i >= n - 1) return true;
        }
        return true;
    }
};