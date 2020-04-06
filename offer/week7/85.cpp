#include <iostream>
using namespace std;



class Solution {
public:
    int add(int num1, int num2){
        while(num2){
            int sum = num1 ^ num2;
            int carry = num1 & num2;
            num1 = sum;
            num2 = carry << 1;
        }
        return num1;
    }
};

int main(){
    auto su = Solution();
    cout << su.add(1, -1);
    return 0;
}