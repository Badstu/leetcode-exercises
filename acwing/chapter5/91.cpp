#include <iostream>
#include <cstring>
using namespace std;

const int N = 20, M = 1 << N;
int a[N][N];
int f[M][N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0; //从0走到0的距离是0
    for(int i = 1; i < (1 << n); i++){
        for(int j = 1; j < n; j++){
            if(i >> j & 1){ //该路径i走到了j
                for(int k = 0; k < n; k++){
                    if(i >> k & 1){ //该路径走到了k
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + a[k][j]);
                    }
                }
            }
        }
    }

    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}