#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5+10;

int M[N];


int qmi(int a, int k, int p){
    int res = 1;
    while(k){
        if (k & 1) res = (LL) res * a % p;
        k >>= 1;
        a = (LL) a * a % p;
    }
    return res;
}

int main(){
    int n, a, k, p;
    cin >> n;
    while(n--){
        scanf("%d%d%d", &a, &k, &p);
        cout << qmi(a, k, p) << endl;
    }

    return 0;
}