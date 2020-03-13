#include <iostream>

using namespace std;

typedef long long LL;

int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }

    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


int main(){
    int n, a, b, x, y, m;
    cin >> n;
    while(n--){
        cin >> a >> b >> m;
        int d = exgcd(a, m, x, y);
        if(!(b % d)) cout << (LL)x * (b / d) % m << endl;
        else cout << "impossible" << endl;
    }

    return 0;
}