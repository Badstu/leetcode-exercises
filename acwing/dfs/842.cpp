#include <iostream>

using namespace std;

const int N = 10;
int n;
bool st[N];
int path[N];

void dfs(int u);

int main(){
    cin >> n;
    dfs(0);
    return 0;
}

void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; i++) cout << path[i] << " ";
        cout << endl;
        return;
    } else{
        for(int i = 1; i <= n; i++){
            if(!st[i]){
                path[u] = i;
                st[i] = true;

                dfs(u + 1);
                
                st[i] = false;
                path[u] = 0;
            }
        }
    }
    return;
}