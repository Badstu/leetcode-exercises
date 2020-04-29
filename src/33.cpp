class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int n = nums.size();

        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r)>> 1;
            if(nums[l] <= nums[mid]){
                if(target >= nums[l] && target <= nums[mid])
                    r = mid + 1;
                else
                    l = mid;
            } else{
                if(target <= nums[r] && target >= nums[mid])
                    l = mid;
                else 
                    r = mid - 1;
            }

        }
        if(nums[l] == target) return l;
        else return -1;
    }

};