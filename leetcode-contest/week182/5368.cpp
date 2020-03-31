
class Solution {
public:
    static const int N = 510;
    int count[510];

    int findLucky(vector<int>& arr) {
        int res = -1;
        int m = 0;
        for(int i = 0; i < arr.size(); i++){
            count[arr[i]]++;
            m = max(m, arr[i]);
        }
        for(int i = 1; i <= m; i++){
            if(i == count[i])
                res = max(res, i);
        }

        return res;
    }
};