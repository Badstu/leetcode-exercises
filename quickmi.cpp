#include <iostream>

using namespace std;

typedef long long LL;

int qmi(int a, int k, int p){ // a^k % p
    int res = 1;
    while(k){
        if(k & 1) res = (LL) res * a % p;
        a = (LL) a * a % p;
        k >>= 1;
    }
    return res;
}

int main(){
    cout << qmi(2, 100, 1e9+7);
    return 0;
}