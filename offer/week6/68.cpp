class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        /* 二分 
        if(nums.empty()) return 0;
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1; //[l, mid], [mid + 1, r]
            if(nums[mid] != mid) r = mid; 
            else l = mid + 1;
        }
        if(nums[r] == r) return n;
        return r;
        */
       
       //高斯求和
       int n = nums.size();
       int sum = 0;
       for(auto x: nums){
           sum += x;
       }
       return n * (n + 1) / 2 - sum;

    }
};