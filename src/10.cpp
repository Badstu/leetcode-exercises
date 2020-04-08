#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<vector<int>> f;
    int n, m;

    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        f = vector<vector<int>>(n+1, vector<int>(m+1, -1));

        return dp(0, 0, s, p);
    }
    
    bool dp(int i, int j, string &s, string &p){
        if(f[i][j] != -1) return f[i][j];

        if(j == m){ //i == n时，p可以跟很多 c*，不用j==n
            if(j == m && i == n) return f[i][j] = 1;
            else return f[i][j] = 0;
        }

        // if(j == m) return f[i][j] = i == n; // '\0' 上面的判断可以换成这个

        bool first_match = i < n && match(s[i], p[j]);
        bool ans;
        if(j + 1 < m && p[j + 1] == '*'){
            ans = dp(i, j + 2, s, p) || (first_match && dp(i + 1, j, s, p));
        } else{
            ans = first_match && dp(i + 1, j + 1, s, p);
        }

        return f[i][j] = ans;
    }

    bool match(char a, char b){
        if(b == '.') return true;
        if(a == b) return true;
        return false;
    }

};