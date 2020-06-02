class Solution {
public:
    int sumNums(int n) {
        int s = 0;
        (n > 0) && (s = n + sumNums(n-1));
        return s;
    }
};