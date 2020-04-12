#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> grid;
    
    int n;
    int res = 0;
    int MOD = 1e9+7;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int numOfWays(int rows) {
        n = rows;
        vector<vector<int>> grid = vector<vector<int>>(n, vector<int>(3, -1));
        dfs(0, 0, res, grid);
        return res;
    }

    void dfs(int i, int j, int sum, vector<vector<int>> &grid){
        if(i == n) return;
        if(j == 3) return dfs(i+1, 0, sum, grid);

        for(int k = 0; k < 3; k++){
            for(int d = 0; d < 4; d++){
                int a = i + dx[d], b = j + dy[d];
                if(a < 0 || a >= n || b < 0 || b >= 3 || grid[a][b] == k) continue;
                if(grid[i][j] == -1){
                    grid[i][j] = k;
                    cout << sum << endl;
                    dfs(i, j + 1, sum + 1, grid);
                    grid[i][j] = -1;
                }
            }
        }
    }
};

int main(){
    Solution s;
    cout << s.numOfWays(1);
    return 0;
}