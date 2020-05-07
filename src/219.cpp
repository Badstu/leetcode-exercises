class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty() || k == 0) return false;
        int n = nums.size();
        unordered_set<int> count;
        for(int i = 0; i < n; i++){
            if(count.find(nums[i]) != count.end()) return true;
            count.insert(nums[i]);
            if(count.size() > k){
                count.erase(nums[i - k]);
            }
        }
        return false;
    }
};