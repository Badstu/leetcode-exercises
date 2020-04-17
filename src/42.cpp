class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(!n) return 0;
        int l_max[n], r_max[n];

        l_max[0] = height[0];
        r_max[n-1] = height[n-1];

        for(int i = 1; i < n; i++){
            l_max[i] = max(l_max[i - 1], height[i]);
        }

        for(int i = n - 2; i >= 0; i--){
            r_max[i] = max(r_max[i+1], height[i]);
        }

        int ans = 0;
        for(int i = 1; i < n - 1; i++){
            ans += min(l_max[i], r_max[i]) - height[i];
        }
        return ans;
    }
};