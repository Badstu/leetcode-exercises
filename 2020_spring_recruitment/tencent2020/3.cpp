#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MOD = 100003;

int qmi(LL a, LL k){
	int res = 1;
	while(k){
		if(k & 1) res = (LL) res * a % MOD;
		k >>= 1;
		a = (LL) a * a % MOD;
	}
	return res;
}


int main(){
	LL n, m;
	int res = 0;
	cin >> m >> n;
	if(m == 1 || n == 1){
		cout << 1 << endl;
		return 0;
	}

	for(int i = 0; i < n; i++){
		int tmp = m % MOD;
		if (i <= n - 3){
			tmp = (LL) tmp * qmi(m, n-3) % MOD;
		}
		tmp = (LL) tmp * (m - 1) % MOD;
		res = (LL) (res + tmp) % MOD;
	}

	cout << res;

	return 0;
}