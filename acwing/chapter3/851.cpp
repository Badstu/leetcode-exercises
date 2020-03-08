#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];

void add(int x, int y, int z) {
    e[idx] = y;
    ne[idx] = h[x];
    w[idx] = z;
    h[x] = idx++;
}

int spfa() {
    memset(dist, 0x3f, sizeof dist);

    queue<int> q;
    q.push(1);

    st[1] = true;
    dist[1] = 0;

    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return dist[n];
}

int main() {
    memset(h, -1, sizeof h);

    cin >> n >> m;
    int x, y, z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        add(x, y, z);
    }

    int dis = spfa();
    if (dis == 0x3f3f3f3f)
        cout << "impossible";
    else
        cout << dis;
    return 0;
}