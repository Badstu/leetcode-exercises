#include <iostream>

using namespace std;

const int N = 11010, M = 2010;
int v[N], w[N], s[N];
int f[M];

int main(){
    int n, m;
    cin >> n >> m;

    int vv, ww, ss, cnt = 1;
    for(int i = 1; i <= n; i++){
        cin >> vv >> ww >> ss;
        int k = 1;
        while(k <= ss){
            v[cnt] = vv * k;
            w[cnt] = ww * k;
            cnt ++;
            ss -= k; //剩下的部分可不可以用2的整次幂表示了
            k *= 2;
        }
        if(ss > 0){
            v[cnt] = vv * ss;
            w[cnt] = ww * ss;
            cnt ++;
        }
    }

    for(int i = 1; i < cnt; i++){
        for(int j = m; j >= v[i]; j--){
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m];

    return 0;
}