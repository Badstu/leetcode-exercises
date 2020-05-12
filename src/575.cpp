class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        if(candies.empty()) return 0;
        sort(candies.begin(), candies.end());

        int n = candies.size();
        int num_kinds = 1;
        for(int i = 1; i < n; i++){
            if(candies[i] != candies[i-1]) {
                num_kinds ++;
            }
        }

        if(num_kinds >= n/2) return n/2;
        else return num_kinds;
    }
};