//
// Created by sayhi on 2020/2/15.
//

#include <iostream>

using namespace std;


int main(){
    double n, mid;
    cin >> n;

    int l = -100, r = 100;
    while(r - l > 1e-8){
        mid = (l + r) / 2;
        if (mid*mid*mid >= n) r = mid;
        else l = mid;
    }
    printf("%6lf\n", l);

    return 0;
}