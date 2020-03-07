//
// Created by sayhi on 2020/2/26.
//

#include <iostream>

using namespace std;

const int N = 1e5+10;
int e[N], l[N], r[N];
int idx;

void init(){
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void del(int k){
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}

void add_to_k_left(int k, int x){
    e[idx] = x;
    r[idx] = k;
    l[idx] = l[k];
    l[k] = idx;
    r[l[k]] = idx;
    idx ++;
}

void add_to_k_right(int k, int x){
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    r[k] = idx;
    l[r[k]] = idx;
    idx ++;
}


int main(){
    int m;
    cin >> m;

    int k, x;
    string c;

    init();

    while(m --){
        cin >> c;
        if(c == "L"){
            cin >> x;
            add_to_k_right(0, x);
        } else if(c == "R"){
            cin >> x;
            add_to_k_left(1, x);
        } else if(c == "D"){
            cin >> k;
            del(k + 1);
        } else if(c == "IL"){
            cin >> k >> x;
            add_to_k_left(k + 1, x);
        } else {
            cin >> k >> x;
            add_to_k_right(k + 1, x);
        }
    }
    for(int i = 0; i < 10; i++) cout << l[i] << " " << e[i] << " "<< r[i] << endl;

    // for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
    return 0;
}
