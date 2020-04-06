class Solution {
public:
    int maxDiff(vector<int>& nums) {
        int minV = 1e9, l = 0;
        for(auto x: nums){
            minV = min(x, minV);
            l = max(l, x - minV);
        }
        return l;
    }
};