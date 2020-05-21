class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int n = s.size();
        vector<vector<bool>> f(n, vector<bool>(n, false));
        int max_length = 1;
        int res_i = 0, res_j = 0;

        for(int l = 0; l < n; l++){
            for(int i = 0; i < n; i++){
                int j = i + l;
                if(j > n - 1) continue;

                if(i == j) f[i][j] = true;
                else if(i + 1 == j) f[i][j] = (s[i] == s[j]);
                else f[i][j] = f[i + 1][j - 1] & (s[i] == s[j]);

                if(f[i][j] && l + 1 > max_length){
                    max_length = l + 1;
                    res_i = i;
                    res_j = j;
                }
            }

        }
        return s.substr(res_i, max_length);
    }

};