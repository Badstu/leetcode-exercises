class Solution {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= mid) r = mid;
            else l = mid + 1;
        }
        if(nums[r] != r) return -1;
        return nums[r];
    }
};