#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <queue>
#include <algorithm>
// #include <pair>

using namespace std;

typedef pair<int, int > PII;

const int N = 1e6+10;

PII range[N];


// struct Range{
//     int l, r;
//     // bool operator< (const Range &W) const{
//     //     return l < W.l;
//     // }
// }range[N];

int main(){
    int n;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
	string s;
    for(int i = 0; i < n; i++){
		int l = 0, r = 0;
		bool flag = false;
		cin >> s;
		for(char c: s){
			if(c == ','){
				flag = true;
				continue;
			}
			if(!flag) l = l * 10 + (c-'0');
			else r = r * 10 + (c-'0');
		}
        if(l == 0 && r == 0){
            continue;
        }
		range[i].first = l;
		range[i].second = r;
    }

    // sort(range, range + n);

    priority_queue<int, vector<int>, greater<int>> heap;

    for(int i = 0; i < n; i++){
        PII r = range[i];
        if(heap.empty() || heap.top() > r.first) heap.push(r.second);
        else{
            heap.pop();
            heap.push(r.second);
        }
    }

    cout << heap.size();

    return 0;
}