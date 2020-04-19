#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
long long a[N] = {0}, b[N] = {0};

int main(){
    int nums_case;
    cin >> nums_case;
    for(int c = 1; c <= nums_case; c++){
        int n;
        long long d;
        cin >> n >> d;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = d / a[i];
        }

        for(int i = n - 2; i >= 0; i--){
            if(b[i] * a[i] > b[i+1] * a[i+1]){
                b[i] = b[i+1] * a[i+1] / a[i];
            }
        }

        cout << "Case #" << c << ": " << b[0]*a[0] << endl;
    }
}


/*
3
3 10
3 7 2
4 100
11 10 5 50
1 1
1
*/