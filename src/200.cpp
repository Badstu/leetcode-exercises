class Solution {
public:
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	vector<int> p;

	int find(int x){
		if(x != p[x]){
			p[x] = find(p[x]);
		}
		return p[x];
	}

    int numIslands(vector<vector<char>>& grid) {
		if(grid.empty() || grid[0].empty()) return 0;
		int n = grid.size();
		int m = grid[0].size();
		// int p[n*m] = {0};
		p = vector<int>(n*m, 0);
		int count = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(grid[i][j] == '1'){
					p[i*m + j] = i*m + j;
					count ++;
				} else{
					p[i*m + j] = -1;
				}
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(grid[i][j] == '1'){
					int cur_root = find(i*m + j);
					for(int k = 0; k < 4; k++){
						int a = dx[k] + i, b = dy[k] + j;
						if(a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == '1'){
							int near_root = find(a*m+b);
							if(near_root != cur_root){
								p[near_root] = cur_root;
								count--;
							}
						}

					}	
				}
			}
		}

		return count;

    }
};