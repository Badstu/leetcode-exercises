#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1010;
int a[12];


int main(){
    string s;
    cin >> s;
    for(int i = 1; i < 10; i++){
        cin >> a[i];
    }

    for(int i = 0; i < s.size(); i ++){
        if(s[i] == '-'){
            cout << '-';
            continue;
        }
        cout << a[s[i] - '0'];
    }

    return 0;
}


/*
输入样例3
0
1 3 6 1 6 8 9 1 3

输出样例3
96631936691613136
*/