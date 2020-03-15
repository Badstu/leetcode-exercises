#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-6;
int n;
double g[N][N];


void cout_matrix(){
    for(int row = 0; row < n; row++){
        for(int col = 0; col <= n; col++){
            cout << g[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int solution(){
    int c, r;
    for(c = 0, r = 0; c < n; c++){
        int t = r;
        for(int i = r; i < n; i++){
            if(fabs(g[i][c]) > fabs(g[t][c]))
                t = i;
        }
        if(fabs(g[t][c]) < eps) continue; //当列全为0，不移动r，待在当前行，移动c到下一列。

        for(int i = c; i <= n; i++) swap(g[t][i], g[c][i]);
        for(int i = n; i >= c; i--) g[r][i] /= g[r][c];

        for(int i = r + 1; i < n; i++)
            for(int j = n; j >= c; j--)
                g[i][j] -= g[i][c] * g[r][j];
        
        r++;
    }

    if(r < n){
        for(int i = r; i < n; i++){
            if(g[i][n] > eps){
                return 2;
            }
        }
        return 1;
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            g[i][n] -= g[i][j] * g[j][n];
        }
    }

    return 0;
}



int main(){
    cin >> n;
    double tmp;
    for(int row = 0; row < n; row++){
        for(int col = 0; col <= n; col++){
            cin >> tmp;
            g[row][col] = tmp;
        }
    }

    int t = solution();

    if(t == 0){
        for(int i = 0; i < n; i ++)
            printf("%.2f\n", g[i][n]);
    } else if(t == 1){
        puts("Infinite group solutions");
    } else{
        puts("No solution");
    }
    return 0;
}