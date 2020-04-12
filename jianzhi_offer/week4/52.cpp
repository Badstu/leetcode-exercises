class Solution {
public:
    int moreThanHalfNum_Solution(vector<int>& nums) {
        int value = -1, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == value){
                cnt ++;
            } else{
                if(cnt) cnt --;
                else{
                    cnt = 1;
                    value = nums[i];
                }
            }
        }
        return value;
    }
};