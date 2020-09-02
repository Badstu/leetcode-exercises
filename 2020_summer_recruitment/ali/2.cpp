#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;
const int R = 110;
int dp[N];
int val[R];

int main(){
	int n, m;
	cin >> n >> m;
	
	int x;
	for(int i = 1; i <= n; i++){
		cin >> x;
		for(int j = 1; j <= x; j++){
			cin >> val[j];
		}
		
		int cur[R] = {0};
		for(int j = 1; j <= x; j++){
			val[j] += val[j-1];
		}
		
		for(int j = 0; j <= x; j++){
			for(int k = 0; k <= x && k+j <= x; k++){
				if(cur[j+k] < val[j] + val[x] - val[x-k]){
					cur[j+k] = val[j] + val[x] - val[x - k];
				}
			}
		}
		for(int j = m; j >= 0; j--){
			for(int k = 0; k <= x; k++){
				if(j + k <= m && dp[j+k] < dp[j] + cur[k]){
					dp[j+k] = dp[j] + cur[k];
				}
			}
		}
	}
	cout << dp[m] << endl;
	return 0;
}