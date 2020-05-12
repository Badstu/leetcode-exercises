// class Solution {
// public:
//     bool isPowerOfFour(int num) {
//         if(num <= 0) return false;
//         while(num > 1){
//             if(num % 4 != 0) return false;
//             num /= 4;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && ((num & (num - 1)) == 0) && ((num & 0xaaaaaaaa) == 0);
    }
};