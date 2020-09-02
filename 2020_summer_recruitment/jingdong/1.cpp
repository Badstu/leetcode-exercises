#include<iostream>

using namespace std;

const int maxn = 1e3+10;
int n, m, k, t;
int dp[110][220], a[110][220];

int main(){
	int i, j;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 2*i-1; j++){
			scanf("%d", &a[i][j]);
		}
	}

	dp[1][1] = a[1][1];
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= 2*i-1; j++){
			if(j-2 >= 1){
				dp[i][j] = max(dp[i][j], dp[i-1][j-2] + a[i][j]);
			}
			if(j-1 >= 1){
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i][j]);
			}
			if(j >= 1){
				dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i][j]);
			}
		}
	}

	int ret = 0;
	for(int i = 0; i <= 2*n - 1; i++){
		ret = max(ret, dp[n][i]);
	}

	printf("%d\n", ret);
	return 0;
}