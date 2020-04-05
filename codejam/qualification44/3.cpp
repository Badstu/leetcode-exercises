#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1010;

struct Range{
    int l, r;
    int index;
    char person;

    bool operator< (const Range &W) const{
        return l < W.l;
    }
}range[N];

struct cmp{
    bool operator()(Range &a, Range &b){
        return a.r > b.r;
    }
};

bool cmp1(Range &a, Range &b){
    return a.index < b.index;
}

int main(){
    int t, n;
    cin >> t;
    for(int ca = 1; ca <= t; ca ++){
        string res;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> range[i].l >> range[i].r;
            range[i].index = i;
        }

        sort(range, range + n);
        priority_queue<Range, vector<Range>, cmp> heap;

        for(int i = 0; i < n; i++){
            auto &r = range[i];
            if(heap.empty()){
                r.person = 'C';
                heap.push(r);
            } else if(r.l >= heap.top().r){
                r.person = heap.top().person;
                heap.push(r);
                heap.pop();
            } else{
                if(heap.size() >= 2){
                    res = "IMPOSSIBLE";
                    break;
                }
                r.person = heap.top().person == 'C' ? 'J' : 'C';
                heap.push(r);
            }
        }

        if(res != "IMPOSSIBLE"){
            sort(range, range+n, cmp1);
            for(int i = 0; i < n; i++){
                res += range[i].person;
            }
        }
        

        cout << "Case #" << ca << ": " << res << endl;
    }

    return 0;
}

/*
4
3
360 480
420 540
600 660
3
0 1440
1 3
2 4
5
99 150
1 100
100 301
2 5
150 250
2
0 720
720 1440
*/