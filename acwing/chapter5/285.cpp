#include <iostream>
#include <cstring>
using namespace std;

const int N = 6010;
int happy[N], h[N], e[N], ne[N], idx = 0;
int f[N][2];
bool has_father[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dfs(int u){
    f[u][1] = happy[u];

    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        dfs(j); //先把子节点的f值（happy）更新过

        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}



int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> happy[i];
    }

    int a, b;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        add(b, a);
        has_father[a] = true;
    }

    int root = 1;
    while(has_father[root]) root++;
    
    dfs(root);

    int res = max(f[root][0], f[root][1]);
    cout << res;
    return 0;
}
