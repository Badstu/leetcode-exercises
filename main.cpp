#include <bits/stdc++.h>

using namespace std;

struct node {
    int x;
    int y;

    bool operator < (const node temp){
        return x < temp.x;
    }
} a, dd[10];


int main(){
    a.x = 1;
    a.y = 2;

    for(int i = 0; i < 10; i++){
        dd[i].x = 10 - i;
        dd[i].y = 2 * (10 - i);
    }

    for(auto t: dd){
        cout << t.x << " " << t.y << endl;
    }

    sort(dd, dd+10);
    
    for(auto t: dd){
        cout << t.x << " " << t.y << endl;
    }

    return 0;
}