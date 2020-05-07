class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int step = 0, max_pose = 0, end = 0;

        for(int i = 0; i < n - 1; i++){
            max_pose = max(max_pose, i+nums[i]);
            if(i == end){
                end = max_pose;
                step++;
            }
        }
        return step;
    }
};