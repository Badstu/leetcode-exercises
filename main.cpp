#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;

    int res = 0;
    while(n >= 10){
        int t = 1;
        while(n != 0){
            t *= n % 10;
            n /= 10;
        }
        n = t;
        res++;
    }
    cout << res << endl;
}
/*
1999999999
*/