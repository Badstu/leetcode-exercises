#include <iostream>
#include <string.h>

using namespace std;

const int N = 1010, M = 15;
char S[N][M], q[M];
int f[M][M];

int edit_distance(char a[], char b[]){
    int la = strlen(a + 1), lb = strlen(b + 1);

    for(int i = 0; i <= la; i++) f[i][0] = i;
    for(int i = 0; i <= lb; i++) f[0][i] = i;

    for(int i = 1; i <= la; i++){
        for(int j = 1; j <= lb; j++){
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
    }
    return f[la][lb];
}


int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> S[i] + 1;
    }

    for(int i = 0; i < m; i++){
        int c, res = 0;
        cin >> q+1 >> c;
        for(int j = 0; j < n; j++){
            if(edit_distance(S[j], q) <= c){
                res++;
            }
        }
        cout << res << endl;
    }

    return 0;
}