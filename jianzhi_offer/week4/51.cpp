class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> permutation(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        path.resize(nums.size());

        dfs(nums, 0, 0, 0);
        return res;
    }

    //@params u: 排列nums里面的第几个元素
    //@params start: 上一个排列的元素在path中的位置
    void dfs(vector<int> &nums, int u, int start, int state){
        if(u == nums.size()){
            res.push_back(path);
            return;
        }
        
        if(!u || nums[u] != nums[u - 1]) start = 0; //看重不重复，如果重复就只能放后面

        for(int i = start; i < nums.size(); i++){
            if(!(state >> i & 1)){
                path[i] = nums[u];
                dfs(nums, u + 1, i + 1, state + (1 << i));
            }
        }
    }

};