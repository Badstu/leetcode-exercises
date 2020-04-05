class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        if(nums.empty()) return 0;
        
        int l = 0, r = nums.size() - 1; 
        while(l < r){
            int mid = l + r >> 1; // [l, mid] [mid + 1, r]
            if(nums[mid] >= k) r = mid;
            else l = mid + 1;
        }
        int left = r;
        
        if(nums[r] != k){
            return 0;
        }

        l = 0, r = nums.size() - 1; 
        while(l < r){
            int mid = l + r + 1 >> 1; // [l, mid - 1] [mid, r]
            if(nums[mid] <= k) l = mid;
            else r = mid - 1;
        }
        int right = l;
        
        return right - left + 1;

    }
};