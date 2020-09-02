#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
typedef long long LL;

int n, m, k, t;

char a[100][100];
int d[100][100];
int vis[100][100];
int cnt;

int p[][2] = {0, 1, 1, 0, -1, 0, 0, -1};

int main(){
	int i, j;
	cin >> n >> m;
	for(i = 1; i <= n; i++){
		scanf("%s", a[i] + 1);
	}

	int ret = 0;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			if(a[i][j] != '.') continue;
			queue<pair<int, int>> pq;
			++cnt;
			vis[i][j] = cnt;
			d[i][j] = 0;
			pq.push({i, j});

			while(!pq.empty()){
				auto x = pq.front();
				pq.pop();
				for(int dir = 0; dir < 4; dir++){
					int tx = x.first + p[dir][0];
					int ty = x.second + p[dir][1];
					if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && vis[tx][ty] != cnt && a[tx][ty] == '.'){
						vis[tx][ty] = cnt;
						pq.push({tx, ty});
						d[tx][ty] = d[x.first][x.second] + 1;
						ret = max(ret, d[tx][ty]);
					}
				}
			}
		}
	}

	cout << ret << endl;
	return 0;

}