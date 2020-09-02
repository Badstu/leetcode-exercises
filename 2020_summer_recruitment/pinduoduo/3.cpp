#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10, M = 1e5+10, T = 2e5+10;
int n, m, t;
int launch_re[N], launch_wei[N], dinner_re[M], dinner_wei[M];
int dp1[T], dp2[T];

int main(){
	cin >> n >> m >> t;
	for(int i = 0; i < n; i++) cin >> launch_re[i] >> launch_wei[i];
	for(int i = 0; i < m; i++) cin >> dinner_re[i] >> dinner_wei[i];

	int re = 0, wei = 0;
	int temp_min_re, temp_max_wei;
	for(int i = 0; i <= t; i++){
		for(int j = 0; j < n; j++){
			re = launch_re[i], wei = launch_wei[i];
			if(wei >= i){
				if(dp1[i] == 0) dp1[i] = re;
				else dp1[i] = min(dp1[i], re);
			}
		}

		for(int j = 0; j < m; j++){
			re = dinner_re[i], wei = dinner_wei[i];
			if(wei >= i){
				if(dp2[i] == 0) dp2[i] = re;
				else dp2[i] = min(dp2[i], re);
			}
		}
	}

	for(int i = 0; i < t; i++){
		
	}
	


	return 0;
}