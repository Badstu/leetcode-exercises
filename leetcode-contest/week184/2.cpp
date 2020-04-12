#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> res;
        int P[m], rP[m+1];
        for(int i = 0; i < m; i++) P[i] = i + 1;
        for(int i = 1; i <= m; i++) rP[i] = i - 1; //下标：P的value, 值：P的下标

        int n = queries.size();
        for(int i = 0; i < n; i++){
            int query = queries[i];
            int index = rP[query];
            // cout << index << endl;

            res.push_back(index);


            rP[query] = 0;
            for(int k = 1; k <= m; k++){
                if(rP[k] < index && k != query){
                    rP[k] ++;
                }
            }

            for(int i = 0; i <= m; i++) cout << rP[i] << " ";
            cout << endl;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> queries = {3, 1, 2, 1};
    int m = 5;
    s.processQueries(queries, m);

    return 0;
}