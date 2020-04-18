class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        if(numbers.empty()) return res;
        int n = numbers.size();
        int i = 0, j = n - 1;

        while(i < j){
            if(numbers[i] + numbers[j] == target){
                res = {i+1, j+1};
                return res;
            }

            if(numbers[i] + numbers[j] < target){
                i++;
            } else if(numbers[i] + numbers[j] > target){
                j--;
            }

        }
        return res;
    }
};