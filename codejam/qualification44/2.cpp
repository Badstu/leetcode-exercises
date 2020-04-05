#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int ca = 1; ca <= t; ca++){
        string s, res;
        stack<char> stk;
        int lp = 0, rp = 0;

        cin >> s;
        for(auto c: s){
            int t = c - '0';
            if(t >= lp){
                int temp = t - lp;
                while(temp--){
                    stk.push('(');
                }
                lp = t;
            } else{
                int temp = lp - t;
                while(temp--){
                    stk.push(')');
                }
                lp = t;
            }
            stk.push(t + '0');
        }
        while(lp--){
            stk.push(')');
        }

        while(stk.size()){
            res += stk.top();
            stk.pop();
        }

        reverse(res.begin(), res.end());

        cout << "Case #" << ca << ": " << res << endl;
    }


    return 0;
}

/*
4
0000
101
111000
1
*/