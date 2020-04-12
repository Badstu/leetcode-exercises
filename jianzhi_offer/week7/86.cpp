class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector<int> B(n, 0);
        int p = 1;
        for(int i = 0; i < n; i++){
            B[i] = p;
            p *= A[i];
        }

        p = 1;
        for(int i = n - 1; ~i; i--){
            B[i] *= p;
            p *= A[i];
        }
        return B;
    }
};