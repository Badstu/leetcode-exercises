class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> record = {{0, 1}};
        int sum = 0;
        for(int element: A){
            sum += element;
            int mod = (sum % K + K) % K;
            ++record[mod];
        }

        int ans = 0;
        for (auto [x, cx]: record){
            ans += cx * (cx - 1) / 2;
        }
        return ans;
    }
};