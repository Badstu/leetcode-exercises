#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 1e5+10;
int a[N];
int n;

int get_max_length(int remove_i){
    int q[N];
    int len = 0;
    for(int i = 0; i < n; i++){
        if(i == remove_i)
            continue;

        int l = 0, r = len;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }

    return len;
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, get_max_length(i));
    }

    cout << res;
    
    return 0;
}


/*
5
2 1 3 2 5
*/