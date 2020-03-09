#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+10, M = 2*1e5+10, INF = 0x3f3f3f3f;
int p[N];
int n, m;

struct Edge{
    int a, b, w;

    bool operator < (const Edge &W) const{ //类内重载less than
        return w < W.w;
    }
} edges[M];


int find(int x){
    if(p[x] != x) p[x] = find(p[x]); //递归，不是while
    return p[x];
}


int kruskal(){
    sort(edges, edges + m);

    for(int i = 1; i <= n; i++) p[i] = i; // 初始化并查集

    int res = 0, cnt = 0;
    for(int i = 0; i < m; i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        int pa = find(a), pb = find(b);
        if(pa != pb){
            p[pa] = pb;
            res += w;
            cnt ++;
        }
    }

    if(cnt < n - 1) return INF;
    return res;
}


int main(){
    cin >> n >> m;
    int u, v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    
    int t = kruskal();

    if(t == INF) cout << "impossible";
    else cout << t;
    return 0;
}