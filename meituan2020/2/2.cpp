#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

const int N = 1010, R = 1010;
int a[N];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    bool flag = true;
    double res = 0;
    
    for(int i = n - 1; i >= 0; i--){
        if(flag){
            res += a[i] * a[i];
            flag = false;
        } else{
            res -= a[i] * a[i];
            flag = true;
        }
    }

    res = res * M_PI;

    printf("%.5lf", res);

    return 0;
}


/*
输入样例3
5
1 2 3 4 5

输出样例3
47.12389
*/