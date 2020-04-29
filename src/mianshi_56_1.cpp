class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int res = 0;
        for(auto x: nums){
            res ^= x;
        }
        
        int low_bit = -res & res;
        int k = 0;
        while(!(low_bit >> k & 1)){
            k++;
        }

        int res1 = 0;
        for(auto x: nums){
            if(x >> k & 1){
                res1 ^= x;
            }
        }
        int res2 = res1^res;

        return {res1, res2};
    }
};