#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 1e5+10;
int n, m, k, t;
LL ret1, ret2;
int mx;
vector<PII> e[maxn];


void dfs(int x, int y=0, int dep=0){
	ret1 += dep;
	mx = max(mx, dep);
	for(auto z: e[x]){
		if(z.first == y) continue;
		dfs(z.first, x, dep+z.second);
	}
}


int main(){
	int i, j;
	cin >> n;
	for(int i = 1; i < n; i++){
		int x, y, w;
		cin >> x >> y >> w;
		e[x].push_back({y, w});
		e[y].push_back({x, w});
		ret2 += w;
	}
	dfs(1);
	cout << ret1 << " " << ret2*2 - mx << endl;
	return 0;
}