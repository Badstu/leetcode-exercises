/*
相似
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
两个数是相似的，当且仅当他们位与起来不为0。例如，3和5是相似的，因为3的二进制为011,5的二进制为101,他们位与起来为001不为0。

现在，给出序列a1,a2…an我们希望你找出，对于任意的i∈[1,n]，是否存在j∈[1,n]，使得ai,aj不相似。

输入
输入第一行包括一个整数n，代表序列a的长度

接下来一行n个数，空格隔开，代表序列a

1<=n<=100000,1<=ai<=106

输出
输出n个数。

如果对于i个数，存在j∈[1,n]，使得ai,aj不相似，输出1,否则输出-1


样例输入
4
3 5 6 1
样例输出
-1 -1 1 1

提示
样例解释：
唯一一对不相似的数是6和1,故6和1的答案为1,其余为-1。
*/


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N], son[N * 8][2], idx = 0;

void insert(int x){
    int p = 0;
    for(int i = 7; i >= 0; i--){
        int last_bit = x >> i & 1;
        if(!son[p][last_bit]) son[p][last_bit] = ++idx;
        p = son[p][last_bit];
    }
}

bool query(int x){
    int p = 0;
    bool flag = true;
    for(int i = 7; i >= 0; i--){
        int last_bit = (x >> i & 1);
        int other_son = last_bit ? 0 : 1;

        if(!son[p][other_son]){
            if(last_bit == 1) flag = false;
            p = son[p][last_bit];
        }
        else p = son[p][other_son];
    }

    return flag;
}


int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        insert(a[i]);
    }

    for(int i = 0; i < n; i++){
        bool flag = query(a[i]);
        
        if(flag) cout << 1 << " ";
        else cout << -1 << " ";
    }

    return 0;
}