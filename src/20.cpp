class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;

        stack<int> stk;
        for(auto c: s){
            if(c == ')'){
                if(stk.empty() || stk.top() != '(') return false;
                else stk.pop();
            }
            else if(c == '}'){
                if(stk.empty() || stk.top() != '{') return false;
                else stk.pop();
            }
            else if(c == ']'){
                if(stk.empty() || stk.top() != '[') return false;
                else stk.pop();
            }
            else{
                stk.push(c);
            }
        }
        return stk.empty();
    }
};