#include <iostream>
#include <cstring>

using namespace std;

const int N = 200, K = N*N, M = 2e4+10;
int n, m, k;
int d[N][N];

void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}


int main() {
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = 0x3f3f3f3f;
        }
    }

    int x, y, z;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }

    floyd();


    while(k--){
        cin >> x >> y;
        if(d[x][y] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
        else cout << d[x][y] << endl;
    }

    return 0;
}