#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, M = 1e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], dist[N]; //dist代表点到集合的最短距离
bool st[N];

int prim() {
	int res = 0; // 要累加或者比大小的都要初始化0
	memset(dist, 0x3f, sizeof dist);

	for(int i = 0; i < n; i++){
		int t = -1;
		for(int j = 1; j <= n; j++){
			if(!st[j] && (t == -1 || dist[t] > dist[j])){
				t = j;
			}
		}

		if(i && dist[t] == INF) return INF;

		if(i) res += dist[t];
		st[t] = true;

		for(int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]); //更新其他点到集合的距离
	}
	return res;
}

int main() {
	memset(g, 0x3f, sizeof g);
    cin >> n >> m;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }

    int res = prim();
	if(res == INF) cout << "impossible";
	else cout << res;

    return 0;
}