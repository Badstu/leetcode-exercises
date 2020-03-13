#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5+10;

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
    int n, a, p;
    cin >> n;
    while(n--){
        scanf("%d%d", &a, &p);
        if(a % p == 0) puts("impossible");
        else cout << qmi(a, p - 2, p) << endl;
    }

    return 0;
}