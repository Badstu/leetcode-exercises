#include <iostream>

using namespace std;

int N = 110;
float g[N][N];

int solution(){
    int t = 0;
    for(int c = 0; c < n; c++){
        int t = c;
        for(int r = c; r < n; r++){
            if(g[r][c] > g[t][c])
                t = r;
        }
        swap(g[t], g[c]);
        for(int i = c; i <= n; i++) g[c][i] /= g[c][c];


    }
}


void cout_matrix(){
    for(int row = 0; row < n; row++){
        for(int col = 0; col <= n; col++){
            cout << g[row][col] << " ";
        }
        cout << endl;
    }
}


int main(){
    int n;
    cin >> n;
    float tmp;
    for(int row = 0; row < n; row++){
        for(int col = 0; col <= n; col++){
            cin >> tmp;
            g[row][col] = tmp;
        }
    }

    int t = solution();
    if(t == 0){
        for(int i = 0; i < n; i ++)
            cout << g[i][n] << endl;
    } else if(t == 1){
        puts("Infinite group solutions");
    } else{
        puts("No solution");
    }
    return 0;
}