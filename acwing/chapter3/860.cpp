#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5+10, M = 2e5+10;
int n, m;
int h[N], e[M], ne[M], idx;
int color[N]; //应该是颜色，而不是布尔值

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int u, int c){
    color[u] = c;

    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!color[j]){
            if(!dfs(j, 3 - c)) return false;
        } else if(color[j] == c) return false;
    }
    return true;
}



int main(){
    memset(h, -1, sizeof h);

    cin >> n >> m;

    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }

    bool flag = true;
    for(int i = 1; i <= n; i++)
        if(!color[i]){
            if(!dfs(i, 1)){
                flag = false; //只要有一点染色失败就算失败
                break;
            }
        }
    if(flag) cout << "Yes";
    else cout << "No";
    return 0;
}