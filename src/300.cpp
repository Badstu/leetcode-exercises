class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        while(nums.empty()) return 0;
        int n = nums.size();
        int tail[n + 1];

        tail[0] = nums[0];
        
        int k = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < tail[k]){
                // 如果当前数比结尾要小，就用二分找到tail中第一个比当前数要大的数
                int l = 0, r = k;
                while(l < r){
                    int mid = l + r >> 1;
                    if(tail[mid] >= nums[i]) r = mid;
                    else l = mid + 1;
                }
                tail[r] = nums[i];
            } else if(nums[i] > tail[k]){
                // 如果当前数比结尾要大，就直接把当前数加到结尾
                tail[++k] = nums[i];
            }
            // 上面两个if可以合并成一个：
            // 不找大的，找tail中比nums[i]要小的最近的数，(二分tail[mid] > nums[i], l = mid; r = mid - 1;)
            // 把nums[i]放到最近的数的后面 (tail[r + 1] = nums[i])
        }
        return k + 1;
    }
};