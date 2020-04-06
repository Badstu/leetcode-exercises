class Solution {
public:
    int getSum(int n) {
        int res = 0;
        (n > 0) && (res = n + getSum(n - 1));
        return res;
    }
};