#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e6+10;
bool st[N];
int primes[N], phi[N], cnt;


LL get_sum(int n){
    phi[1] = 1; //1 的欧拉函数是 1
    for(int i = 2; i <= n; i ++){
        if(!st[i]){
            phi[i] = i - 1;
            primes[cnt++] = i;
        }
        for(int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0){
                phi[primes[j] * i] = primes[j] * phi[i];
                break;
            } else{
                phi[primes[j] * i] = phi[i] * (primes[j] - 1);
            }
        }
    }

    LL res = 0;
    for(int i = 1; i <= n; i++){
        res += phi[i];
    }
    return res;
}



int main(){
    int n;
    cin >> n;
    LL res = get_sum(n);
    cout << res;

    return 0;
}