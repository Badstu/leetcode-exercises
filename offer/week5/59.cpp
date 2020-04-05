class Solution {
public:
    
    int getTranslationCount(string s) {
        int n = s.size() + 1;
        int f[n];
        f[0] = 1;
        f[1] = 1;
        for(int i = 2; i < n; i ++){
            f[i] = f[i - 1];
            if(s.substr(i - 2, 2) >= "10" && s.substr(i - 2, 2) <= "25"){
                f[i] += f[i - 2];
            }
        }

        return f[n - 1];
    }
};