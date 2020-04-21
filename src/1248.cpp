class Solution {
public:
    // typedef pair<int, int> PII;

    // int numberOfSubarrays(vector<int>& nums, int k) {
    //     if(nums.empty()) return 0;
    //     int n = nums.size();
    //     // int i = 0, j = 0; 
    //     int count_odd = 0;
    //     vector<int> odds;
    //     odds.push_back(-1);
        
    //     for(int i = 0; i < n; i++){
    //         if(nums[i] % 2 == 1){
    //             odds.push_back(i);
    //         }
    //     }

    //     odds.push_back(n);
    //     int m = odds.size();

    //     int res = 0;
    //     for(int i = 1; i + k < m; i++){
    //         int j = i + k - 1;

    //         int start = odds[i];
    //         int end = odds[j];

    //         int left_choices = start - odds[i - 1];
    //         int right_choices = odds[j+1] - end;
    //         res += left_choices * right_choices;
    //     }
    //     return res;
    // }

    vector<int> prefixCnt;
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        prefixCnt.resize(n+1, 0);
        prefixCnt[0] = 1; //当前奇数个数为0的子数组有1个(什么都不取)

        int res = 0, prefix_sum = 0;
        for(int i = 0; i < n; i++){
            prefix_sum += nums[i] & 1;
            prefixCnt[prefix_sum]++;

            if(prefix_sum >= k){
                res += prefixCnt[prefix_sum - k];
            }
        }
        return res;

    }
};