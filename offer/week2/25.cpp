#include <iostream>

using namespace std;


class Solution {
public:
    int maxProductAfterCutting(int n) {
        int res = 1;
        if(n <= 3){
            res = 1 * (n - 1);
            return res;
        }

        if(n % 3 == 1){
            res *= 4;
            n -= 4;    
        }else if(n % 3 == 2){
            res *= 2;
            n -= 2;
        }

        while(n){
            res *= 3;
            n -= 3;
        }

        return res;
    }
};


int main(){
    Solution s;
    cout << s.maxProductAfterCutting(3);

    return 0;
}