class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> res;
        if(grid.empty() || grid[0].empty()) return res;
        int n = grid.size(), m = grid[0].size();


        while(k--){
            vector<int> tmp;
            for(int i = 0; i < n; i++){
                tmp.push_back(grid[i][m-1]);
            }

            for(int j = m - 1; j > 0; j--){
                for(int i = 0; i < n; i++){
                    grid[i][j] = grid[i][j - 1];
                }
            }

            for(int i = n - 1; i > 0; i--){
                grid[i][0] = tmp[i - 1];
            }

            grid[0][0] = tmp[n - 1];
        }
        return grid;
    }
};