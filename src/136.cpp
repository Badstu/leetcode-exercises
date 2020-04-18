class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int s = nums[0];
        for(int i = 1; i < n; i++){
            s ^= nums[i];
        }
        return s;
    }
};