#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int im[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> im[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int c = 1;
			int t = im[i][j];
			for(int k = 0; k < 4; k++){
				int nx = dx[k] + i;
				int ny = dy[k] + j;
				if(nx < 0 || nx >= n || ny < 0 || ny >= m){
					continue;
				}
				t += im[nx][ny];
				c += 1;
			}
			float tt = t * 1.0 / c;
			im[i][j] = round(tt);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << im[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}