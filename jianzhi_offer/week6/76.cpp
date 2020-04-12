class Solution {
public:
    vector<vector<int> > findContinuousSequence(int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        int s = 0;
        for(int i = 1, j = 1; i < sum; i++){
            while(s < sum){
                s += j;
                j ++;
            }

            if(s == sum){
                for(int k = i; k < j; k++) tmp.push_back(k);
                res.push_back(tmp);
                tmp.clear();
            }

            s -= i;
        }
        return res;
    }
};