class Solution {
public:
    int maxProduct(vector<int>& nums) {
		if(nums.empty()) return 0;
		int n = nums.size();
		int max_f = 1, min_f = 1;
		int ans = INT_MIN;
		for(int j = 0; j < n; j++){
			int t_max = max_f, t_min = min_f;
			max_f = max({t_max * nums[j], t_min * nums[j], nums[j]}); 
			//一定要选这个数，或者可以不选前面的数，即就从这个数开始，用ans记录下整个过程的最大值
			min_f = min({t_max * nums[j], t_min * nums[j], nums[j]});
			ans = max(ans, max_f);
		}
		return ans;
    }
};