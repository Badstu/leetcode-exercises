class Solution {
public:
    int mincostTickets(vector<int>& d, vector<int>& c) {
        int n = d.size();
        vector<int> f = vector<int>(n+1, INT_MAX);
        f[0] = 0;
        int start = 0;
        for(int i = 1; i <= n; i++){
            f[i] = f[i - 1] + c[0];
            int t_7 = search_day(d, start, i - 1, d[i-1] - 6);
            if(d[t_7] >= d[i-1] - 6){
                f[i] = min(f[i], f[t_7 + 1] + c[1]);
                // start = t_7;
            }
            int t_30 = search_day(d, start, i - 1, d[i-1] - 29);
            if(d[t_30] >= d[i-1] - 29){
                f[i] = min(f[i], f[t_30 + 1] + c[2]);
                // start = t_7;
            }
        }

        for(int i = 0; i <= n; i++){
            cout << i << " " << f[i] << endl;
        }
        return f[n];
    }

    int search_day(vector<int>& days, int l, int r, int target){
        while(l < r){
            int mid = l + r >> 1;
            if(days[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};