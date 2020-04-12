#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 20010;
int a[N], b[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);

    LL sum_a = 0, sum_b = 0;
    for(int i = n - 1; i >= n - 3; i--){
        sum_a += a[i];
        sum_b += b[i];
    }

    if(sum_a >= sum_b) cout << sum_a;
    else cout << sum_b;

    return 0;
}


/*
5
1 2 3 4 5
1 2 3 4 6
*/