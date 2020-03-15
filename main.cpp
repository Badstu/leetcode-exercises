// 默写快速幂

#include<iostream>

using namespace std;

int qmi(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = (LL) res * a % p;
        k >>= 1;
        a = (LL) a * a % p;
    }
    return res;
}