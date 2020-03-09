#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int N = 110, MOD = 1e9+7;
unordered_map<int, int> primes;

void get_primes(int x){
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0){
            while(x % i ==0){
                x /= i;
                primes[i] ++;
            }
        }
    }
    if(x > 1) primes[x] ++;
}


int main(){
    int n, a;
    cin >> n;
    while(n --){
        cin >> a;
        get_primes(a);
    }

    LL res = 1;
    for(auto prime: primes){
        int zhi = prime.second;
        res = res * (zhi+1) % MOD; //先乘再取模
    }

    cout << res;
}