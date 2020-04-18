#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1010;
int a[N];
int st[N];
int n, h0;
int nums = 0;

int dfs(int i, int h0);

int main(){
    cin >> n >> h0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    nums = dfs(0, h0);
    cout << nums;
    return 0;
}

int dfs(int i, int h0){
    if(i == n - 1) return 1;
    if(i >= n) return 0;

    int ans = 0;

    ans += dfs(i + h0, h0);

    if(h0 != a[i]){
        ans += dfs(i + a[i], a[i]);
    }
    return ans;
}


/*
跳格子
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
一共有n个格子从左到右排成了一行，从1~n编号。第 i 个格子上写着一个正整数a[i]。

一开始你在1号格子，并且手里有一个数字h0。

当你在第 i 号格子，手里有数字 h 的时候，你有两个选择：

（1）跳到第i + h号格子，手中的数字依然是h；

（2）跳到第i + a[i]号格子，手中的数字变成a[i]；

在跳跃的过程中是不允许超出n号格子的。

你想知道一共有多少种不同的路径，可以从1号格子跳到n号格子，两条路径是不同的当且仅当它们经过的格子集合是不同的。输出不同路径的条数除以998244353的余数。

输入
第一行包含两个整数n和h0；

第二行包含n个正整数a[i]；

2 <= n <= 1000, 1 <= a[i], h0 <= n - 1

输出
输出对应的答案。


样例输入
5 1
2 3 2 4 3
样例输出
4


提示
输入样例2
3 10
10 10 10

输出样例2
0
*/