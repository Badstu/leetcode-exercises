#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int n, m, k, t;
int w[maxn], v[maxn];
int dp[maxn], ok[maxn];


int main(){
	int i, j;
	scanf("%d%d", &k, &n);

	for(i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}

	for(i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}
	ok[0] = 1;

	for(i = 1; i <= n; i++){
		for(j = k; j >= w[i]; j--){
			
			if(ok[j - w[i]]){
				ok[j] = 1;
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
	}

	for(i = k; i >= 0; i--){
		if(ok[i]){
			printf("%d\n", dp[i]);
			return 0;
		}
	}
	puts("0");
	return 0;

}