#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
typedef long long LL;

int n, m, k, t;
struct node{
	int id, t;
	bool operator<(const node& p){
		return t < p.t;
	}
}a[N];

int vis[4];

int main(){
	int i, j;
	int cnt = 0;
	cin >> n;
	for(i = 1; i <= 4; i++){
		int temp[10];
		for(j = 0; j < n; j++){
			cin >> temp[j];
		}

		for(j = 1; j < 1<<n; j++){
			int cur = 0;
			for(k = 0; k < n; k++){
				if(j >> k & 1){
					cur += temp[k];
				}
			}
			a[cnt++] = {i, cur};
		}
	}

	sort(a+1, a+cnt+1);
	
	int pos = 0;
	int dif = 1e9;
	int all = 0;
	for(i = 1; i <= cnt; i++){
		while(pos + 1 <= cnt && all < 4){
			if(++vis[a[pos+1].id] == 1){
				all++;
			}
			++pos;
		}

		if(all == 4) dif = min(dif, a[pos].t - a[i].t);
		if(--vis[a[i].id] == 0){
			all--;
		}
	}

	cout << dif << endl;
	return 0;
}

