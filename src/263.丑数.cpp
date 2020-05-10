/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    typedef long long LL;
    bool isUgly(int num) {
        vector<LL> q(1, 1);
        int i = 0, j = 0, k = 0;

        LL tmp = 1;
        while(tmp < num){
            tmp = min({q[i] * 2, q[j] * 3, q[k] * 5});
            q.push_back(tmp);
            if(tmp == q[i] * 2) i++;
            if(tmp == q[j] * 3) j++;
            if(tmp == q[k] * 5) k++;
        }
        if(q.back() == num) return true;
        else return false;
    }
};
// @lc code=end

