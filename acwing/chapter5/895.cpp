#include <iostream>

using namespace std;

const int N = 1010;
int f[N], a[N];


int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    //f[0] = 0
    for(int i = 1; i <= n; i++){
        f[i] = 1; //只有a[i]一个数(j == 0)
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]){ //因为不知道a[j]是啥
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i ++) res = max(res, f[i]);

    cout << res;


    return 0;
}