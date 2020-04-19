#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

const int N = 1010;
const LL MOD = 1e9;
long long a[N] = {0}, b[N] = {0};


bool is_number(char a);
bool is_director(char a);
void count_director(string s, int t);
PLL direc2vec(char a);
PLL dfs(string s);

int main(){
    int nums_case;
    cin >> nums_case;
    for(int c = 1; c <= nums_case; c++){
        string s;
        stack<char> stk;
        
        cin >> s;
        if(!is_number(s[0])){
            s = "1(" + s;
            s += ')';
        }

        auto res = dfs(s);

        LL w = 1, h = 1;
        w = (LL)(w + res.second) % MOD;
        h = (LL)(h + res.first) % MOD;

        if(w <= 0) w = (LL)1e9 + w;
        if(h <= 0) h = (LL)1e9 + h;
        
        cout << "Case #" << c << ": " << w << " " << h << endl;
    }
}

PLL dfs(string s){
    PLL res = {0, 0};
    LL times = s[0] - '0';
    for(int i = 1; i < s.size(); i++){
        if(s[i] == '(' || s[i] == ')'){
            continue;
        }
        if(is_director(s[i])){
            auto vv = direc2vec(s[i]);
            // cout << s[i] << " " << vv.first << " " << vv.second << endl;
            res.first += vv.first;
            res.second += vv.second;
            continue;
        }
        if(is_number(s[i])){
            int j = i + 1, k = 0;
            for(; j < s.size(); j++){
                if(s[j] == '(') k++;
                if(s[j] == ')') k--;
                if(k == 0) break;
            }
            auto v = dfs(s.substr(i, j - i + 1));
            // cout << "vvv " << i << " " << v.first << " " << v.second << endl;
            // cout << i << " " << res.first << " " << res.second << endl;
            res.first += v.first;
            res.second += v.second;
            // cout << i << " " << res.first << " " << res.second << endl;
            i = j;
            continue;
        }
        // cout << i << " " << res.first << " " << res.second << endl;
    }
    res.first *= times;
    res.second *= times;
    return res;
}



bool is_number(char a){
    if(a > '0' && a < '9'){
        return true;
    }
    return false;
}

bool is_director(char a){
    if(a == 'S' || a == 'N' || a == 'W' || a == 'E'){
        return true;
    }
    return false;
}


PLL direc2vec(char a){
    if(a == 'N'){
        return {-1, 0};
    }
    if(a == 'S'){
        return {1, 0};
    }
    if(a == 'W'){
        return {0, -1};
    }
    if(a == 'E'){
        return {0, 1};
    }
}



/*
4
SSSEEE
N
N3(S)N2(E)N
2(3(NW)2(W2(EE)W))
*/