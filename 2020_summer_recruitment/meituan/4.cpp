#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e2+10;
int dp[maxn][maxn];
int ret[maxn][maxn];
int ok[maxn][maxn];

void dfs(int l, int r){
	if(l >= r) return;
	if(ok[l][r]) return;
	for(int i = l; i < r; i++){
		dfs(l, i);
		dfs(i+1, r);
		ret[l][r] = max(ret[l][r], ret[l][i]+ret[i+1][r]);
		if(dp[l][i] && dp[i+1][r] && dp[l][i] == dp[i+1][r]){
			dp[l][r] = dp[l][i] + 1;
			ret[l][r] = max(ret[l][r], ret[l][i] + ret[i+1][r] + 1);
		}
		ok[l][r] = 1;
	}
}

int main(){
	int n;
	int i, j;
	cin >> n;
	for(i = 1; i <= n; i++){
		cin >> dp[i][i];
	}

	dfs(1, n);
	cout << ret[1][n] << endl;
	return 0;
}