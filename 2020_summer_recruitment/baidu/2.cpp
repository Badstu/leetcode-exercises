#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int A[N][N], dp[N][N];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int main(){
	int n;
	cin >> n;
	if (n == 1){
		cout << 0 << endl;
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> A[i][j];
			dp[i + 1][j + 1] = 1e9;
		}
	}

	dp[1][1] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int t = A[i - 1][j - 1];
			for(int k = 0; k < 4; k++){
				int nx = i + dx[k], ny = j + dy[k];
				if(nx < 1 || nx > n || ny < 1 || ny > n){
					continue;
				}
				dp[i][j] = min(dp[i][j], dp[nx][ny] + abs(t - A[nx - 1][ny - 1]));
			}
		}
	}
	cout << dp[n][n] << endl;

	return 0;
}