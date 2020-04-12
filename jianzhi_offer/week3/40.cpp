class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int x = 0, y = 0, d = 1;
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if(matrix.empty() || matrix[0].empty()) return vector<int>();
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> st(n, vector<bool>(m, false));
        vector<int> res;
        res.push_back(matrix[0][0]);
        st[0][0] = true;

        for(int i = 0; i < n*m - 1; i++){
            int a = x + dx[d], b = y + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= m || st[a][b]){
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            res.push_back(matrix[a][b]);
            x = a, y = b;
            st[a][b] = true;
        }
        return res;
    }
};