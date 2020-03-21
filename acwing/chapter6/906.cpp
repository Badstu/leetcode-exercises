#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5+10;

struct Range{
    int l, r;
    bool operator< (const Range &W) const{
        return l < W.l;
    }
}range[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> range[i].l >> range[i].r;
    }

    sort(range, range + n);

    priority_queue<int, vector<int>, greater<int>> heap;

    for(int i = 0; i < n; i++){
        Range r = range[i];
        if(heap.empty() || heap.top() >= r.l) heap.push(r.r);
        else{
            heap.pop();
            heap.push(r.r);
        }

        // if(!heap.size()) heap.push(r.r);
        // else{
        //     int max_r = heap.top();
        //     if(r.l <= max_r){
        //         heap.push(r.r);
        //     } else {
        //         heap.pop();
        //         heap.push(r.r);
        //     }
        // }
    }

    cout << heap.size();

    return 0;
}