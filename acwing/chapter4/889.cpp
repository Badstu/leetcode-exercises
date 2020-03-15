#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10, MOD = 1e9+7;

int qmi(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = (LL) res * a % p;
        k >>= 1;
        a = (LL) a * a % p;
    }
    return res;
}

int main(){
    int n;
    cin >> n;

    //卡特兰数1/(n+1) * C_2n^n
    LL res = 1;
    for(int i = 1, j = 2*n; i <= n; i++, j--){
        res = (LL) res * j % MOD;
        res = (LL) res * qmi(i, MOD - 2, MOD) % MOD;
    }
    res = (LL) res * qmi(n + 1, MOD - 2, MOD) % MOD; //1/(n+1)也是逆元
    cout << res;
    return 0;
}