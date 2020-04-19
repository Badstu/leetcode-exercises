#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N] = {0};

int main(){
    int nums_case;
    cin >> nums_case;
    for(int c = 1; c <= nums_case; c++){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int res = 0;
        int p = a[0];
        for(int i = 1; i < n - 1; i++){
            if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                res++;
            }
        }

        cout << "Case #" << c << ": " << res << endl;
    }


}