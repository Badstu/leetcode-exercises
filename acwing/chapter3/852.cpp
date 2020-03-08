#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 2010, M = 10010;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int x, int y, int z) {
    e[idx] = y;
    ne[idx] = h[x];
    w[idx] = z;
    h[x] = idx++;
}

bool spfa() {
    // memset(dist, 0x3f, sizeof dist);
    // dist[1] = 0;
    // 不再从1开始走，所有点的距离都是0；

    queue<int> q;
    for (int i = 0; i < n; i++) {
        st[i] = true;
        q.push(i);
    }

    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) { //给负权边写的
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    memset(h, -1, sizeof h);

    cin >> n >> m;
    int x, y, z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        add(x, y, z);
    }

    if(spfa()) cout << "Yes";
    else
        cout << "No";
    return 0;
}