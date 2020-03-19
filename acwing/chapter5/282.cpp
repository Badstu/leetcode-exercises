#include <iostream>

using namespace std;

const int N= 310, INF = 1e9;
int a[N], s[N], f[N][N];


int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }


    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len - 1 <= n; i++){
            int l = i, r = i + len - 1;
            f[l][r] = INF;
            for(int k = l; k <= r - 1; k++){
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
                // cout << r <<" "<< l << " " << s[r] - s[l - 1] << endl;
            }
        }
    }
    cout << f[1][n];

    return 0;
}