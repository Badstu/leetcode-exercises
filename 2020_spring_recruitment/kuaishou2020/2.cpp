
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


int main(){
	vector<vector<int> > A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	int n = A.size();
	int m = A[0].size();

	// vector<vector<int>> f(n, vector<int> m);
	int f[n][m];
	memset(f, 0x3f, sizeof f);
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};

	// write code here
	f[0][0] = A[0][0];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < 4; k++){
				int a = i + dx[k];
				int b = j + dy[k];
				if(a >= 0 && a < n && b >= 0 && b < m){
					f[i][j] = min(f[i][j], f[a][b] + A[i][j]);
				}
			}
		}
	}
	
	cout << f[n - 1][m - 1];

	return f[A.size() - 1][A[0].size() - 1];
}