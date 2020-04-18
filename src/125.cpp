#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int i = 0, j = s.size() - 1;
        while(i < j){
            while((!is_charac(s[i]) && !is_number(s[i])) && i < j) i++;
            while((!is_charac(s[j]) && !is_number(s[j])) && i < j) j--;
            if(!isEqual(s[i], s[j])){
                return false;
            }
            if(isEqual(s[i], s[j])){
                i++;
                j--;
            }
        }
        return true;
    }

    bool isEqual(char a, char b){
        if(a == b) return true;
        if(is_charac(a) && is_charac(b) && abs(a-b) == 32) return true;
        if(is_number(a) && is_number(b) && a == b) return true;
        return false;
    }

    bool is_charac(char a){
        if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')){
            return true;
        }
        return false;
    }

    bool is_number(char a){
        if(a >= '0' && a <= '9'){
            return true;
        }
        return false;
    }
};

// int main(){
//     char a, b;
//     cin >> a >> b;
//     cout << (int)a << " " << (int)b << endl;
// }