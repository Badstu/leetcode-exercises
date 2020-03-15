#include <iostream>

using namespace std;

const int N = 2010, MOD = 1e9+7;
int C[N][N], n;


void init(){
    for(int i = 0; i < N; i ++){
        for(int j = 0; j <= i; j++){
            if(!j) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
}

int main(){
    cin >> n;
    init();
    int a, b;
    while(n--){
        cin >> a >> b;
        cout << C[a][b] << endl;
    }

    return 0;
}