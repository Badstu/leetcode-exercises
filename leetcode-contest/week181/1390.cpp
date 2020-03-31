#include <iostream>

using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pair<int, int> t = get_divisor_num(nums[i]);
            int count = t.first, sum = t.second;
            if(count == 4){
                res += sum;
            }
        }
        return res;
    }

    pair<int, int> get_divisor_num(int n){
        int res = 1;
        int sum = 1;
        for(int i = 2; i <= n/i; i++){
            if(n % i == 0){
                int s = 0;
                while(n % i == 0){
                    n /= i;
                    s ++;
                }
                res *= (s + 1);
                int t = 1;
                while(s--) t = (t * i + 1);
                sum *= t;
            }
        }
        if(n > 1){
            res *= 2;
            sum *= (n + 1);
        }

        return {res, sum};
    }

};