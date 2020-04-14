#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+10, M = 1e6+10, L = 1e4+10;
int f[N][N];
int g[N][N];
int dist1[N];
int dist2[N];

bool st[N];
int n, m, x;


void dijkstra1(int x);
void dijkstra2(int x);

int main(){
	memset(f, 0, sizeof f);

	cin >> n >> m >> x;
	int a, b, w;
	while(m--){
		cin >> a >> b >> w;
		f[a][b] = w; //从1开始计数（点）
		g[b][a] = w;
	}

	dijkstra1(x);
	dijkstra2(x);

	int res = 0;
	for(int i = 1; i <= n; i++){		
		if(dist1[i] == 0x3f3f3f3f || dist2[i] == 0x3f3f3f3f) continue;
		cout << i << " " << dist1[i] << " " << dist2[i] << endl;
		int d = dist1[i] + dist2[i];
		if(d > res){
			res = d;
		}
	}

	cout << res << endl;

	return 0;
}


void dijkstra1(int x){
	memset(dist1, 0x3f, sizeof dist1);
	memset(f, 0x3f, sizeof f);
	dist1[x] = 0;

	for(int i = 0; i < n - 1; i++){
		int t = -1;
		for(int j = 1; j <= n; j++){
			if(!st[j] && (t == -1 || dist1[t] > dist1[j])){
				t = j;
			}
		}

		st[t] = true;
		
		for(int j = 1; j <= n; j++){
			dist1[j] = min(dist1[j], dist1[t] + f[t][j]);
		}
	}
	return;
}

void dijkstra2(int x){
	memset(dist2, 0x3f, sizeof dist2);
	memset(g, 0x3f, sizeof f);
	memset(st, false, sizeof st);
	dist2[x] = 0;
	for(int i = 0; i < n - 1; i++){
		int t = -1;
		for(int j = 1; j <= n; j++){
			if(!st[j] && (t == -1 || dist2[t] > dist2[j])){
				t = j;
			}
		}

		st[t] = true;
		for(int j = 1; j <= n; j++){
			dist2[j] = min(dist2[j], dist2[t] + g[t][j]);
		}
	}
	return;
}

/*
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

10
*/