#include <iostream>
using namespace std;


class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        while(i < s.size() && s[i] == ' ') i ++;
        int j = s.size() - 1;
        while(j >= 0 && s[j] == ' ') j --;
        if(i > j) return false;

        s = s.substr(i, j - i + 1);

        if(s[0] == '-' || s[0] == '+') s = s.substr(1);
        if(s.empty()) return false;
        
        int is_dot = 0;
        int is_E = 0;

        for(int i = 0; i < s.size(); i++){
            // cout << s[i] << " " << is_number(s[i]) << endl;
            if(!is_number(s[i])) return false;
            else{
                if(s[i] == '.'){
                    is_dot ++;
                    if(is_dot > 1 || is_E > 0 || s.size() == 1) return false;
                }
                if(s[i] == 'e' || s[i] == 'E'){
                    is_E ++;
                    if(is_E > 1 || i == s.size() - 1 || i == 0 || (s[i - 1] < '0' || s[i - 1] > '9'))
                        return false;
                }
                if(s[i] == '+' || s[i] == '-'){
                    if(i == 0) return false;
                    if(i != 0 && (s[i - 1] != 'e' && s[i - 1] != 'E')){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool is_number(char c){
        if(c < '0' || c >'9'){
            if(c != '.' && c != 'E' && c != 'e' && c != '+' && c != '-'){
                return false;
            }    
        }
        return true;
    }
};


int main(){
    Solution s;
    string str = "1.e+5";
    cout << s.isNumber(str);
    return 0;
}