#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, K = 510, M = 1e4 + 10;
int n, m, k;
int dist[N], backup[N];

struct {
    int a, b, w;
} edges[M];

int bellman_ford() {
    memset(dist, 0x3f3f3f3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < k; i++) {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2)
        return -1;
    else
        return dist[n];
}

int main() {
    cin >> n >> m >> k;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges[i].a = a;
        edges[i].b = b;
        edges[i].w = c;
    }

    int distance = bellman_ford();
    if (distance == -1)
        cout << "impossible";
    else
        cout << distance;

    return 0;
}