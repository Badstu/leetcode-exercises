class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();

        int res = merge_sort(nums, 0, n - 1);
        return res;
    }

    int merge_sort(vector<int>& nums, int l, int r){
        if (l >= r) return 0;
        int mid = l + r >> 1;
        int res = merge_sort(nums, l, mid) + merge_sort(nums, mid+1, r);

        int i = l, j = mid + 1;
        vector<int> tmp;
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                tmp.push_back(nums[i]);
                i++;
            } else{
                tmp.push_back(nums[j]);
                j++;
                res += mid - i + 1;
            }
        }

        while(i <= mid) tmp.push_back(nums[i++]);
        while(j <= r){
            tmp.push_back(nums[j++]);
            res++;
        }

        for(int i = l, j = 0; i <= r; i++, j++){
            nums[i] = tmp[j];
        }
        return res;
    }

};