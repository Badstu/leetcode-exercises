#include <iostream>

using namespace std;

class Solution {
public:
    int NumberOf1(int n) {
        unsigned int t = n;
        int res = 0;

        while(t){
            t -= lowbit(t);
            res ++;
        }
        return res;
    }

    int lowbit(int n){
        return n & (-n);
    }
};


int main(){

    return 0;
}