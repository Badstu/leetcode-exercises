class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> res(n, 0);
        int max = *max_element(candies.begin(), candies.end());
        for(int i = 0; i < n; i++) {
            if(candies[i]+extraCandies >= max){
                res[i] = true;
            }
        }
        return res;
    }
};