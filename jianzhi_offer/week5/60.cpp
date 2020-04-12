class Solution {
public:
    int getMaxValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        // for(int i = 0; i <= m; i++) f[0][i] = 0;
        // for(int i = 0; i <= n; i++) f[i][0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        return f[n][m];
    }
};