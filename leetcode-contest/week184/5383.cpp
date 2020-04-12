#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        int MOD = 1e9+7;
        if(n == 0) return 0;
        if(n == 1) return 12;
        long long repeat = 6, unrepeat = 6;
        for(int i = 2; i <= n; i++){
            int new_repeat = (repeat * 3) % MOD + (unrepeat * 2) % MOD;
            int new_unrepeat = (repeat * 2) % MOD + (unrepeat * 2) % MOD;
            repeat = new_repeat, unrepeat = new_unrepeat;
        }

        return (repeat + unrepeat) % MOD;
    }

    
};

int main(){
    Solution s;
    cout << s.numOfWays(3);
    return 0;
}