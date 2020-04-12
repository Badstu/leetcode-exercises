#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < 0 || nums[i] >= n){
                return -1;
            }
        }

        for(int i = 0; i < n; i++){
            while(nums[i] != i && nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
            if(nums[i] != i && nums[nums[i]] == nums[i]) return nums[i];
        }

        return -1;
    }
};


int main(){
    Solution s;
    vector<int> nums = {2, 3, 5, 4, 3, 2, 6, 7};
    cout << s.duplicateInArray(nums) << endl;
    return 0;
}