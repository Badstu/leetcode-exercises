#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+10;

struct Range{
    int l, r;
    bool operator< (const Range &W)const{
        return r < W.r;
    }
}range[N];


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> range[i].l >> range[i].r;
    }
    
    sort(range, range+n);
    

    int res = 0, ed = -2e9;
    for(int i = 0; i < n; i++){
        Range r = range[i];
        if(r.l > ed){
            res ++;
            ed = r.r;
        }
    }

    cout << res;

    return 0;
}