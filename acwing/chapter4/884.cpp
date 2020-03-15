#include <iostream>

using namespace std;

const int N = 110;
int g[N][N], n;

void cout_matrix(){
    cout << "=============" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    cout << "=============" << endl;
}

int gauss(){
    int r, c;
    for(r = c = 0; c < n; c++){
        cout_matrix();
        int t = r;
        for(int i = r; i < n; i++){
            if(g[i][c]){
                t = i;
            }
        }

        if(!g[t][c]) continue;
        for(int i = c; i <= n; i++) swap(g[t][i], g[r][i]);

        for(int i = r + 1; i < n; i++){
            for(int j = n; j >= c; j--){
                if(g[i][c]) g[i][j] ^= g[r][j];
            }
        }

        r++;
        cout_matrix();
    }

    if(r < n){
        for(int i = r; i < n; i ++){
            if(g[i][n]) return 2;
        }
        return 1;
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            g[i][n] ^= g[i][j] & g[j][n];
        }
    }

    return 0;
}


int main(){
    cin >> n;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j <= n; j++){
            cin >> g[i][j];
        }
    }

    int t = gauss();

    if(t == 0){
        for(int i = 0; i < n; i++) cout << g[i][n] << endl;
    } else if(t == 1){
        cout << "Multiple sets of solutions";
    } else if(t == 2){
        cout << "No solution";
    }

    return 0;
}