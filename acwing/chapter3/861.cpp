#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010, M = 1e5+10;
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(match[j] == 0 || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}



int main(){
    memset(h, -1, sizeof h);

    cin >> n1 >> n2 >> m;
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        add(u, v);
    }

    int res = 0;
    for(int i = 1; i <= n1; i++){
        memset(st, false, sizeof st);
        if(find(i)) res ++;
    }

    cout << res << endl;
    return 0;
}