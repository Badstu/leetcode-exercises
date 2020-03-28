#include <iostream>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        double res = 1;
        int a = abs(exponent);
        while(a--){
            res *= base;
        }
        if(exponent < 0) return 1 / res;

        return res;
    }
};


int main(){
    Solution s;
    cout << s.Power(10, 0);

    return 0;
}