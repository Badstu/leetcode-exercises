#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int k = 0; 

        s += ' ';
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == ' ' && s[i + 1] == ' '){
                s.erase(i, 1);
            }
        }

        n = s.size();
        s.erase(n - 1, 1);
        if(s[0] == ' ') s.erase(0, 1);

        reverse(s.begin(), s.end());

        k = 0;
        for(int i = k; i < n; i++){
            if(s[i] == ' ' || s[i] == '\0'){
                reverse(s.begin() + k, s.begin() + i);
                k = i + 1;
            }
        }

        return s;
    }
};