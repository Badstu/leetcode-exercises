#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 110;
int f[N][N][N];
int t[N];
int n, k, m;
int st[N];


void cout_matrix(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            for(int c = 0; c <= m; c++){
                cout << i << " " << j << " " << c << " " << f[i][j][c] << endl;
            }
        }
    }
}


int main(){
    cin >> n >> k >> m;
    int p, q;
    cin >> p >> q;
    for(int i = 1; i <= k; i++) cin >> t[i];
    
    int score = 0;
    f[0][0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            for(int time = 0; time <= m; time++){
                f[i][j][time] = f[i - 1][j - 1][time];
                if(t[j] <= time){
                    if(st[i] == k - 1){
                        score = p + q;
                    } else{
                        score = p;
                    }
                    // cout << score << endl;
                    if(f[i - 1][j - 1][time - t[j]] + score > f[i][j][time]){
                        f[i][j][time] = f[i - 1][j - 1][time - t[j]] + score;
                        st[i] ++;
                    };
                }
            }
        }
    }

    // cout_matrix();
    cout << f[n][k][m];
    return 0;
}


/*
3 2 8
3 1
9 5

2 2 3
1 2
1 1

*/