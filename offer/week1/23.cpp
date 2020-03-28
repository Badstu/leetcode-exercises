class Solution {
public:
    bool hasPath(vector<vector<char>>& matrix, string &str) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(matrix, str, 0, i, j))
                    return true;
            }
        }
        return false;
    }


    bool dfs(vector<vector<char>> &matrix, string &str, int u, int x, int y){
        if(matrix[x][y] != str[u]) return false;
        if(u == str.size() - 1) return true;

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        char t = matrix[x][y];
        matrix[x][y] = '*';
        for(int i = 0; i < 4; i++){
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < matrix.size() && b >= 0 && b < matrix[0].size())
                if(dfs(matrix, str, u + 1, a, b)) return true;
        }
        matrix[x][y] = t;

        return false;
    }
};