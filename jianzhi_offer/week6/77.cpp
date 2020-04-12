class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        for(int i = 0; i < s.size(); i++){
            int j = i;
            while(s[j] != ' ' && j < s.size()) j++;

            reverse(s.begin() + i, s.begin() + j);
            i = j;
            // break;
        }
        return s;
    }
};