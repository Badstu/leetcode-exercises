#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 1e9+10, tmp_j = 1e4+10;
int n, m;
int a[N][2];
// int f[N][tmp_j];

int main(){
	cin >> n >> m;
	vector<vector<int>> a = vector<vector<int>>(n, vector<int>(2, 0));
	int total_xue = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i][0] >> a[i][1];
		total_xue += a[i][0];
	}

	// memset(f, 0, sizeof f);
	vector<double> f = vector<double>(total_xue+1, 0);

	double res = 0;
	for(int i = 1; i <= n; i++){
		double ci = a[i-1][0], wi = a[i-1][1];
		for(int j = total_xue; j >= 1; j--){
			if(ci <= j){
				f[j] = max(f[j], f[j - ci] + wi - ((double)ci/m));
			}

			res = max(f[j], res);
			// if((f[j] - (j+m-1)/m) > res){
			// 	res = f[j] - (j + m - 1)/m;
			// }
		}
	}

	// int res = 0;
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= total_xue; j++){
	// 		f[i][j] = f[i][j] - (j+m-1)/m;
	// 		res = max(f[i][j], res);
	// 		// cout << f[i][j] << " ";
	// 	}
	// }

	cout << ceil(res) << endl;
	return 0;
}
