#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1010;
int a[N];
int st[N];
int n, h0;
int nums = 0;

int dfs(int i, int h0);

int main(){
    cin >> n >> h0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    nums = dfs(0, h0);
    cout << nums;
    return 0;
}

int dfs(int i, int h0){
    if(i == n - 1) return 1;
    if(i >= n) return 0;

    int ans = 0;

    ans += dfs(i + h0, h0);

    if(h0 != a[i]){
        ans += dfs(i + a[i], a[i]);
    }
    return ans;
}


/*
样例输入
3 10
10 10 10
5 1
2 3 2 4 3
样例输出
4
*/