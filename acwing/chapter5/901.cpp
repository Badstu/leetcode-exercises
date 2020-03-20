#include <iostream>
#include <cstring>
using namespace std;

const int N = 310;
int r, c;
int a[N][N], f[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dp(int x, int y){
    int &v = f[x][y];
    if(v != -1) {
        return v;
    }

    v = 1;
    for(int i = 0; i < 4; i++){
        int m = x + dx[i], n = y + dy[i];
        if(m >= 1 && m <= r && n >= 1 && n <= c && a[m][n] < a[x][y]){
            v = max(v, dp(m, n) + 1);
        }
    }

    return v;
}


int main(){
    cin >> r >> c;

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
        }
    }

    memset(f, -1, sizeof f);
    int res = 0;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            res = max(res, dp(i, j));

    cout << res;
}