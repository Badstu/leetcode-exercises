class Solution {
public:
    stack<int> stk;
    bool isPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() != popV.size()) return false;

        for(int i = 0, j = 0; i < pushV.size(); i++){
            int t = pushV[i];
            stk.push(t);
            //要用while
            while(!stk.empty() && stk.top() == popV[j]){
                stk.pop();
                j++;
            }
        }

        if(stk.empty()) return true;
        else return false;
    }
};