#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string replaceSpaces(string &str) {
        string res;
        for(auto c: str){
            if(c == ' '){
                res += "%20";
            }else{
                res += c;
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    string str = "We are happy";
    cout << s.replaceSpaces(str);
}