#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> PII;
    int m, n;
    queue<PII> q;

    int pos_sum(int x, int y){
        int sum = 0;
        while(x){
            sum += x % 10;
            x /= 10;
        }
        while(y){
            sum += y % 10;
            y /= 10;
        }
        return sum;
    }

    int movingCount(int threshold, int rows, int cols)
    {
        if(!rows || !cols) return 0;
        vector<vector<bool>> st(rows, vector<bool>(cols, false));
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        
        int res = 1;
        q.push({0, 0});
        st[0][0] = true;

        while(q.size()){
            auto t = q.front();
            int x = t.first, y = t.second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int a = x + dx[i], b = y + dy[i];
                if(a >= 0 && a <= rows - 1 && b >= 0 && b <= cols - 1){
                    if(!st[a][b] && pos_sum(a, b) <= threshold){
                        q.push({a, b});
                        st[a][b] = true;
                        res += 1;
                    }
                }
            }
        }
        return res;
    }
};


int main(){
    Solution s;

    cout << s.movingCount(7, 4, 5);

    return 0;
}

