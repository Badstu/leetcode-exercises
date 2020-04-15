class Solution {
public:
	typedef pair<int, int> PII;
	vector<vector<int>> dist;
	vector<vector<int>> matrix;
	int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& ma) {
		matrix = ma;
		n = matrix.size(), m = matrix[0].size();
		dist = vector<vector<int>> (n, vector<int>(m, -1));
		
		queue<PII> q;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(matrix[i][j] == 0){
					q.push({i, j});
					dist[i][j] = 0;
				}
			}
		}

		while(q.size()){
			PII t = q.front();
			q.pop();

			int x = t.first, y = t.second;
			for(int i = 0; i < 4; i++){
				int a = x + dx[i], b = y + dy[i];
				if(a >= 0 && a < n && b >= 0 && b < m && dist[a][b] == -1){
					q.push({a, b});
					dist[a][b] = dist[x][y] + 1;
				}
			}
		}
        
		return dist;
    }

};