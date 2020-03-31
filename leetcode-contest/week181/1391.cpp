class Solution {
public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int state[6][4] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 1, 0, 0}
    };
    

    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> st(n, vector<bool>(m, false));
        return dfs(0, 0, grid, st);
    }

    bool dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& st){
        if(x == n - 1 && y == m - 1) return true;
        int k = grid[x][y];
        
        for(int i = 0; i < 4; i++){
            int a = x + dx[i], b = y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= m || st[a][b]) continue;
            if(state[k - 1][i] && state[grid[a][b] - 1][i ^ 2]){
                st[x][y] = true;
                if(dfs(a, b, grid, st)) return true;
                st[x][y] = false;
            }
        }
        return false;
    }
};