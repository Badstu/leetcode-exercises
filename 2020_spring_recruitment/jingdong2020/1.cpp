#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;

const int N = 50010;
int a[N];

int main(){
    int n, m;
    cin >> n >> m;
    priority_queue<int> que;

    int t;
    for(int i = 0; i < n; i++){
        cin >> t;
        a[i] = t;
    }
    sort(a, a+n);

    int nums_q, q;
    cin >> nums_q;
    while(nums_q--){
        que = priority_queue<int>();
        cin >> q;
        for(int i = 0; i < q; i++){
            que.push(a[i]);
        }

        int k = 0;
        int loss = 0, day = 1;
        while(que.size()){
            t = que.top();
            que.pop();
            loss += day * t;
            k++;
            if(k >= m){
                k = 0;
                day ++;
            }
        }

        cout << loss << endl;
    }

    return 0;
}


/*
及时止损
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
最近经济不景气，小A准备将持仓的股票抛售一部分，他共持有n支股票，受交易平台的限制，他每天最多只能卖出m支股票，已知第i支股票每天会亏损a_i元，即如果第k天抛售这支股票，亏损的数额是k*a_i元。

现在他还没有决定具体卖出多少支股票，所以他会给你若干个询问，即如果卖出q支股票，这q支股票最少的亏损数额是多少元。

输入
输入第一行包含两个正整数n和m，表示小A持仓的股票数量和每天最多能卖出的股票数量。(1<=n,m<=50000)

输入第二行包含n个正整数，第i个数a_i表示第i支股票每天的亏损数额。(1<=a_i<=10000)

接下来一行有一个正整数Q，表示询问的数量。(1<=Q<=50000)

之后有Q行，每行有一个正整数q，表示假如要卖出q支股票，最少的亏损数额是多少元。(q<=n)

输出
对于每个询问，输出对应的结果。


样例输入
5 2
1 2 3 4 5
2
3
5
样例输出
7
22

提示
样例解释：
一共有5支股票，每天最多可以抛售2支
q为2，即有两个询问
针对第一个询问3，需要抛售3支股票，当选择第1、2、3号股票时损失最小。其中第一天抛售2、3号股票，损失为5元；第二天抛售1号股票，损失为2*1=2元；最后合计损失为7元。
针对第二个询问5，需要抛售第1、2、3、4、5号股票。其中第一天抛售4、5号股票，损失为9元；第二天抛售2、3号股票，损失为2*2+2*3=10；第三天抛售1号股票，损失为3*1=3元；最后合计损失22元。
*/
