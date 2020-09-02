#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10, M = 1e5+10, T = 2e5+10;
int n, m, k, t;

struct node{
	int a, b;
	bool operator<(const node& p) const{
		return b < p.b;
	}
}c[N], d[N];

int main(){
	cin >> n >> m >> k;
	int ret = 1e9;
	for(int i = 1; i <= n; i++){
		cin >> c[i].a >> c[i].b;
		if(c[i].b >= k) ret = min(ret, c[i].a);
	}

	sort(c+1, c+n+1);
	for(int i = 1; i <= m; i++){
		cin >> d[i].a >> d[i].b;
		if(d[i].b >= k) ret = min(ret, d[i].a);
	}
	sort(d+1, d+m+1);

	if(k ==0) return 0*puts("0");
	if(ret != 1e9) return 0*printf("%d\n", ret);
	int pos = m, cur = 1e9;
	for(int i = 1; i <= n; i++){
		while(pos >= 1 && d[pos].b+c[i].b >= k){
			cur = min(cur, d[pos].a);
			pos --;
		}
		if(cur != 1e9) ret = min(ret, c[i].a + cur);
	}

	if(ret == 1e9) puts("-1");
	else printf("%d\n", ret);
	
	return 0;
}