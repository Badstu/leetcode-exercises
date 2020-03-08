#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;

    heap.push({0, 1}); //把第1点和其距离放入堆中，初始化集合

    while(heap.size()){
        auto t = heap.top();
        heap.pop();

        int ver = t.second, d = t.first;
        if(st[ver])
            continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > d + w[i]){
                dist[j] = d + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f)
        cout << -1;
    else
        cout << dist[n];
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        add(a, b, c);
    }

    dijkstra();

    return 0;
}