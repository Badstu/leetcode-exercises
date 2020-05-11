class Solution {
public:
    double myPow(double x, int n1) {
        long long n = n1;
		if(x == 0) return 0;
		if(n == 0) return 1;

		bool flag = false;
		if(n < 0){
			flag = true;
			n = -1 * n;
		}

		double res = 1;
		while(n){
			if(n & 1) res *= x;
			x = x * x;
			n >>= 1;
		}

		if(flag){
            res = 1 / res;
        }

		return res;
    }
};