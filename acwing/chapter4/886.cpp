#include <iostream>

using namespace std;
typedef long long LL;

const int N = 1e5+10, MOD = 1e9+7;
int fact[N], infact[N], n;

int qmi(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = (LL) res * a % p;
        k >>= 1;
        a = (LL) a * a % p;
    }
    return res;
}

void init(){
    fact[0] = 1;
    infact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (LL)fact[i-1] * i % MOD;
        infact[i] = (LL)infact[i - 1] * qmi(i, MOD - 2, MOD) % MOD;
    }
}

int main(){
    cin >> n;
    init();

    int a, b;
    while(n--){
        cin >> a >> b;
        cout << (LL)fact[a] * infact[b] % MOD * infact[a-b] % MOD << endl;
    }
    return 0;
}