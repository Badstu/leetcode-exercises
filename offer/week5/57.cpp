class Solution {
public:
    int digitAtIndex(int n) {
        long long base = 1, s = 9;
        int i = 1;
        while(n > i * s){
            n -= s * i;
            i ++;
            s *= 10;
            base *= 10;
        }

        int number = base + (n + i - 1)/i - 1;
        int p = n % i ? n % i : i;
        for(int j = 0; j < i - p; j++){
            number /= 10;
        }

        return  number % 10;
    }
};