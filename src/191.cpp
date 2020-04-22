class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0){
            uint32_t lowbit = -n & n;
            n -= lowbit;
            count++;
        }
        return count;
    }
};