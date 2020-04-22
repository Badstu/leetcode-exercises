// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int max_count = 0;
//         int n = nums.size();
//         unordered_map<int, int> count;
//         int res = 0;
//         for(int i = 0; i < n; i++){
//             int t = nums[i];
//             count[t] += 1;
//             if(count[t] > max_count){
//                 max_count = count[t];
//                 res = t;
//             }
//         }

//         return res;
//     }
// };


// 投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = -1;

        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                candidate = nums[i];
            }
            count += (nums[i] == candidate) ? 1 : -1;
        }
        return candidate;
    }
};