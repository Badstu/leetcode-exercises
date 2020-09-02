#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e5+10, lim = 117649, mod = 1e9+9;

int n, m, k, t;
LL dp[2][lim];
char a[10][10];

void trans(LL dp1[], LL dp0, int state[], char* str, int cur, int pos, int last){
	if(pos < 0){
		(dp1[cur] += dp0) %= mod;
		return;
	}
	if(str[pos] == '*'){
		trans(dp1, dp0, state, str, cur*7+0, pos-1, 0);
	} else{
		for(int i = 1; i <= 6; i++){
			if(i == last || i == state[pos]) continue;
			trans(dp1, dp0, state, str, cur*7+i, pos-1, i);
		}
	}
}

int main(){
	for(int i = 1; i <= 6; i++){
		scanf("%s", a[i]+1);
	}
	int cur = 0;
	dp[0][0] = 1;

	for(int i = 1; i <= 6; i++){
		cur ^= 1;
		memset(dp[cur], 0, sizeof(dp[cur]));
		for(int j = 0; j < lim; j++){
			if(!dp[cur^1][j]) continue;
			int x = j;
			int b[6];

			for(int k = 0; k < 6; k++){
				b[k] = x % 7;
				x /= 7;
			}
			trans(dp[cur], dp[cur^1][j], b, a[i]+1, 0, 5, -1);
		}
	}
	LL res = 0;
	for(int i = 0; i < lim; i++){
		(res += dp[cur][i]) %= mod;
	}
	cout << res << endl;
}