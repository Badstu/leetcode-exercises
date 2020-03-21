#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10;

struct Range {
    int l, r;
    bool operator < (const Range &W) const {
        return l < W.l;
    }
}range[N];


int main(){
    int n, st, ed;
    scanf("%d%d%d", &n, &st, &ed);

    for(int i = 0; i < n; i++){
        cin >> range[i].l >> range[i].r;
    }

    sort(range, range + n);

    int res = 0;
    for(int i = 0; i < n; i++){
        auto r = range[i];
        if(r.l > st){
            res = -1;
            break;
        }

        int max_r = r.r;
        int j = i;
        while(j < n && range[j].l <= st){
            max_r = max(max_r, range[j].r);
            j ++;
        }

        st = max_r;
        res ++;
        i = j - 1;
    }

    if(st < ed){
        res = -1;
    }

    cout << res;

    return 0;
}