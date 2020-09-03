#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 10;

int n, m, k, t;

char a[maxn][maxn];
bool vis[maxn][maxn];

int dir[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void dfs(int x, int y){
	vis[x][y] = true;
	for(int i = 0; i < 4; i++){
		int _x = x + dir[i][0];
		int _y = y + dir[i][1];
		if(_x >= 1 && _x <= m && _y >= 1 && _y <= n && !vis[_x][_y] && a[_x][_y] == 'S'){
			dfs(_x, _y);
		}
	}
}

int main(){
	int i, j;
	scanf("%d,%d", &m, &n);
	for(i = 1; i <= m; i++){
		scanf("%s", a[i]+1);
	}

	int ret = 0;
	for(i = 1; i <= m; i++){
		for(j = 1; j <= n; j++){
			if(a[i][j] == 'S' && !vis[i][j]){
				dfs(i, j);
				ret += 1;
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}