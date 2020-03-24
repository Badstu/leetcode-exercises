#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int len = nums.size(); // n+1
        int l = 1, r = len - 1;
        while(l < r){
            int s = 0;
            int mid = l + r >> 1; // [l, mid], [mid+1, r]
            for(auto x: nums){
                if(x >= l && x <= mid){
                    s ++;
                }
            }

            if(s > mid - l +1) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 3, 5, 4, 3, 2, 6, 7};
    cout << s.duplicateInArray(nums) << endl;
    return 0;
}