class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty()) return res;
        int n = matrix.size(), m = matrix[0].size();
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

        vector<vector<int>> visted(n, vector<int>(m, 0));
        int x = 0, y = 0, k = 0;
        res.push_back(matrix[0][0]);
        visted[0][0] = 1;

        for(int i = 0; i < (n*m)-1; i++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visted[nx][ny] != 0){
                k = (k + 1) % 4;
                nx = x + dx[k], ny = y + dy[k];
            }

            res.push_back(matrix[nx][ny]);
            visted[nx][ny] = 1;
            x = nx, y = ny;
        }

        return res;
    }
};