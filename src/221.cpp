class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        int max_side = 0;

        vector<vector<int>> f (n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            if(matrix[i][0] == '1') f[i][0] = 1;
            max_side = max(max_side, f[i][0]);
        }

        for(int i = 0; i < m; i++){
            if(matrix[0][i] == '1') f[0][i] = 1;
            max_side = max(max_side, f[0][i]);
        }

        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == '1'){
                    f[i][j] = min({f[i-1][j], f[i][j-1], f[i-1][j-1]}) + 1;
                    max_side = max(max_side, f[i][j]);
                }
            }
        }

        return max_side*max_side;
    }
};