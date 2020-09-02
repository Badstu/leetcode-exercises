#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

int dp[N];

int main(){
	int n, m;
	cin >> n >> m;
	
	while(n--){
		int time, val;
		cin >> time >> val;
		for(int i = m; i >= time; i--){
			dp[i] = max(dp[i], dp[i-time] + val);
		}
	}

	cout << dp[m] << endl;
	return 0;
}