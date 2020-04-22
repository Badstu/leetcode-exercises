class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f[n+1];
        f[0] = 0;
        f[1] = nums[1];
        f[2] = max(nums[1], nums[2]);

        for(int i = 3; i <= n; i++){
            f[i] = max(f[i - 2] + nums[i - 1], f[i - 1]);
        }
        return f[n];
    }
};