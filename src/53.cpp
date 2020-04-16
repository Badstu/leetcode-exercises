class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = INT_MIN, s = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(s < 0) s = 0;
            s += nums[i];

            res = max(s, res);
        }

        return res;
    }
};