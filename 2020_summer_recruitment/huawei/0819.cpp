#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 1e3+10, MOD = 1e9+7;
unordered_map<int, int> hash_map;

int f[N];

long long C(int n, int m)
{
	if (m < n - m) m = n - m;
	long long ans = f[n];
	ans = ans / (f[m] * f[n-m]);

	// for (int i = m + 1; i <= n; i++){
	// 	ans = ans * i;
	// }
	// for (int i = 1; i <= n - m; i++) {
	// 	ans = ans / i;
	// }
	return ans % MOD;
}


int main(){
	int n, t;
	int res = 1;
	int max_depth = 0;

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		hash_map[t] += 1;
		max_depth = max(t, max_depth);
	}

	f[0] = 1;
	for(int i = 1; i <= max_depth; i++){
		f[i] = f[i - 1] * i;
	}


	if(hash_map.find(0) == hash_map.end()){
		cout << 0 << endl;
		return 0;
	}

	int last_depth = 0, last_node = hash_map[0];
	for(int i = 1; i <= max_depth; i++){
		if(i < max_depth && hash_map.find(i) == hash_map.end() || hash_map[i] > last_node * 2){
			cout << 0 << endl;
			return 0;
		}
		
		res = ((LL) res * (C(last_node * 2, hash_map[i]) % MOD)) % MOD;

		last_depth = i;
		last_node = hash_map[i];
	}
	
	cout << res << endl;
	return 0;
}
