#include <iostream>

using namespace std;

const int N = 1010;
char A[N], B[N];
int f[N][N];

int main(){
    int n, m;
    scanf("%d%s", &n, A+1);
    scanf("%d%s", &m, B+1);

    for(int i = 1; i <= n; i++) f[i][0] = i;
    for(int i = 1; i <= m; i++) f[0][i] = i;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (A[i] != B[j]));
        }
    }

    cout << f[n][m];

    return 0;
}