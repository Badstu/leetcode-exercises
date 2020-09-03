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
    
    int res = 0;
	for(i = 1; i <= n; i++){
		for(j = k; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}

    printf("%d\n", dp[k]);
	return 0;

}