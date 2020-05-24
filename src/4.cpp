class Solution {
public:
    int findK(vector<int>& nums1, vector<int>& nums2, int k){
        int n = nums1.size();
        int m = nums2.size();
        int index1 = 0, index2 = 0;

        while(true){
            if(index1 == n){
                return nums2[index2 + k - 1];
            }
            if(index2 == m){
                return nums1[index1 + k - 1];
            }
            if(k == 1){
                return min(nums1[index1], nums2[index2]);
            }
            

            int newIndex1 = min(index1 + k / 2 - 1, n - 1);
            int newIndex2 = min(index2 + k / 2 - 1, m - 1);

            int v1 = nums1[newIndex1];
            int v2 = nums2[newIndex2];
            if(v1 <= v2){
                k -= (newIndex1 - index1 + 1);
                index1 = newIndex1 + 1;
            } else {
                k -= (newIndex2 - index2 + 1);
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        double res = 0;
        if((n + m) % 2 != 0){
            res = findK(nums1, nums2, ((n+m)/2)+1);
        } else {
            res = (findK(nums1, nums2, (n+m)/2) + findK(nums1, nums2, ((n+m)/2)+1)) / 2.0;
        }
        return res;
    }

};