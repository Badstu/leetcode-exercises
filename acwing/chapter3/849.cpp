#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 1e5+10;
int g[N][N], dist[N];
bool st[N];

int main(){
	memset(dist, 0x3f, sizeof dist);
	memset(g, 0x3f, sizeof g);

	int n, m;
	cin >> n >> m;
	int a, b, w;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> w;
		g[a][b] = min(g[a][b], w);
	}

	dist[1] = 0;
	for(int i = 0; i < n - 1; i++){
		int t = -1;

		for(int j = 1; j <= n; j++){
			if(!st[j] && (t == -1 || dist[t] > dist[j])){
				t = j;
			} //找到集合外距离最小的点
		}

		for(int j = 1; j <= n; j++){
			dist[j] = min(dist[j], dist[t] + g[t][j]);
		} // 用dist[t]更新dist[j]

		st[t] = true; //把t加入到集合中
	}
	if(dist[n] == 0x3f3f3f3f) cout << -1;
	else cout << dist[n];

}