#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 1e5+10, mod = 998244353;

int n, m, k, t;

int main(){
	int i, j;
	cin >> t;
	while (t--){
		cin >> n;
		int x = 0;
		while(n--){
			cin >> j;
			x = __gcd(x, j);
		}
		if(x == 1) cout << 0 << endl;
		else cout << -1 << endl;
	}

	return 0;
}