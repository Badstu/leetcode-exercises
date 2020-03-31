#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> target;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int pos = index[i];
            int value = nums[i];
            target.insert(target.begin()+pos, value);
        }
        return target;
    }
};

int main(){
    Solution s;
    cout << s.createTargetArray();
    return 0;
}