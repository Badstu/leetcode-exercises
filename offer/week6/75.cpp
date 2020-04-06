class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        unordered_set<int> hash;

        for(auto x: nums){
            if(hash.count(target - x) == 1){
                return vector<int>{x, target - x};
            }
            hash.insert(x);
        }
        
    }
};