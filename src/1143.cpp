#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int f[n + 1][m + 1];
        memset(f, 0, sizeof f);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if(text1[i] == text2[j])
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
        return f[n][m];
    }
};