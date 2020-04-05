class Solution {
public:
    unordered_map<char, int> count;

    char firstNotRepeatingChar(string s) {
        // if(s.empty()) return '#';
        for(char c: s) count[c] ++;

        for(char c: s)
            if(count[c] == 1)
                return c;

        return '#';
    }
};