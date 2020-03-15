#include <iostream>
#include <unordered_set>
#include <cstring>

using namespace std;

const int N = 110, M = 10010;
int s[N], p[N], f[M];
int n, k;

int sg(int x){
    if(f[x] != -1) return f[x];

    unordered_set<int> S;
    for(int i = 0; i < k; i++){
        int sum = s[i];
        if(x >= sum) S.insert(sg(x - sum));
    }

    for(int i = 0; ; i++){
        if(!S.count(i)){
            return f[x] = i;
        }
    }
}


int main(){
    cin >> k;
    for(int i = 0; i < k; i++) cin >> s[i];

    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i];
    
    memset(f, -1, sizeof f);

    int res = 0;
    for(int i = 0; i < n; i++){
        res = res ^ sg(p[i]);
    }

    if(res) puts("Yes");
    else puts("No");
}