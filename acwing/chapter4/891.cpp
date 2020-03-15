#include <iostream>
using namespace std;

const int N = 1e5+10;
int p[N];


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i];

    int res = 0; // 可以等于0，因为所有石子堆石子个数都大于0
    for(int i = 0; i < n; i ++){
        res = res ^ p[i];
    }
    if(res) puts("Yes");
    else puts("No");
    

    return 0;
}