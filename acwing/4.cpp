#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+10;
int h[N], e[N], ne[N], w[N], idx = 0;
int dist[N];
bool st[N];

void add(int a, int b, int weight){
    e[idx] = b;
    w[idx] = weight;
    ne[idx] = h[a];
    h[a] = idx;
    idx ++;
}


int main(){
    int n, m, s;
    cin >> n >> m >> s;

    memset(h, -1, sizeof h);

    int u, v, c;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> c;
        add(u, v, c);
        add(v, u, c);
    }

    dist[s] = 0;
    for(int i = 0; i < n - 1; i++){
        int t = -1;

        for(int j = h[s]; j != -1; j = ne[j]){
            int k = e[j];
            if(!st[k] && (t == -1 || dist[t] > dist[j])){
                t = k;
            }
        }

        for(int j = h[t]; j != -1; j = ne[j]){
            int k = e[j], c = w[j];
            dist[k] = min(dist[k], dist[t] + c);
        }
        st[t] = true;
    }
    
    for(int i = 1; i <= n; i++){
        if(dist[i] > ){

        }
    }
}