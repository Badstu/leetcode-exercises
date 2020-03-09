#include <iostream>

using namespace std;

const int N = 1e6+10;
int primes[N], cnt = 0;
bool st[N];

//朴素->埃氏筛法
void prime(int x){
    for(int i = 2; i <= x; i++){
        if(!st[i]){
            primes[cnt++] = i;
            for(int j = i+i; j <= x; j += i){
                st[j] = true;
            }
        }
    }
}

//线性筛法，用最小质因子pj来筛去所有的i*pj
void prime(int x){
    for(int i = 2; i <= x; i++){
        if(!st[i]) primes[cnt++] = i;

        for(int j = 0; primes[j] <= x / i; j++){
            st[i * primes[j]] = true;
            if(i % primes[j] == 0) break; //保证pj是i的最小质因子
        }
    }
}


int main(){
    int n;
    cin >> n;
    prime(n);
    cout << cnt;
    return 0;
}