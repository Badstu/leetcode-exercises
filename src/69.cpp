class Solution {
public:
    typedef long long LL;

    int mySqrt(int x) {
        LL l = 0, r = x;
        while(l < r){
            LL mid = (l + r + 1) >> 1;
            if(mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return r;
    }
};

//公式转化法
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        
        int ans = exp(0.5 * log(x));
        
        return ((long long)(ans+1) * (ans+1) <= x) ? ans+1 : ans;
    }
};

//牛顿法
class Solution {
public:
    int mySqrt(int x) {
        double x0 = x;
        while(true){
            double xi = 0.5 * (x0 + (x / x0));
            if(fabs(xi - x0) < 1e-7) break;
            x0 = xi;
        }
        return int(x0);
    }
};