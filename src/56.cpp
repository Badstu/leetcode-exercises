class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty()) return res;

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0], max_r = intervals[0][1];
        for(int i = 1; i < n; i++){
            int l = intervals[i][0], r = intervals[i][1];
            if(l <= max_r){
                max_r = max(max_r, r);
            } else{
                res.push_back({start, max_r});
                start = l;
                max_r = r;
            }
        }

        res.push_back({start, max_r});

        return res;
    }
};