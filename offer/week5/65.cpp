class Solution {
public:
    int inversePairs(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int res = merge_sort(nums, l, r);
        return res;
    }

    int merge_sort(vector<int> &nums, int l, int r){
        if(l >= r) return 0;
        int mid = l + r >> 1;
        int n = merge_sort(nums, l, mid) + merge_sort(nums, mid + 1, r);

        vector<int> temp;
        int i = l, j = mid + 1;
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i ++;
            } else {
                temp.push_back(nums[j]);
                n += mid - i + 1;
                j ++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i++]);
        }
        while(j <= r){
            temp.push_back(nums[j++]);
        }

        int k = l;
        for(auto x: temp){
            nums[k++] = x;
        }

        return n;
    }

};