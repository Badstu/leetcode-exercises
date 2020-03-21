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
    scanf("%d%d%d", &st, &ed, &n);

    for(int i = 0; i < n; i++){
        cin >> range[i].l >> range[i].r;
    }

    sort(range, range + n);

    int res = 0;
    for(int i = 0; i < n; i++){
        if(range[i].l > st){
            res = -1;
            break;
        }

        int j = i, max_r = range[i].r;
        while(j < n && range[j].l <= st){
            max_r = max(max_r, range[j].r);
            j ++;
        }

        st = max_r;
        res ++;
        if(st >= ed) break;

        i = j - 1;
    }

    if(st < ed) cout << -1;
    else cout << res;

    return 0;
}