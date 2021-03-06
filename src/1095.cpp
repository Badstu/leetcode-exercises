/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int res = 10000;
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                l = mid + 1;
            } else r = mid;
        }

        int peak = l;
        l = 0, r = peak;
        while(l < r){
            int mid = l + r >> 1;
            if(mountainArr.get(mid) >= target) r = mid;
            else l = mid + 1;
        }
        if(mountainArr.get(l) != target){
            l = peak + 1, r = n - 1;
            while(l < r){
                int mid = l + r >> 1;
                if(mountainArr.get(mid) <= target) r = mid;
                else l = mid + 1;
            }
        }

        return (mountainArr.get(l) == target)? l: -1;
    }
};