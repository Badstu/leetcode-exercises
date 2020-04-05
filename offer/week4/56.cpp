class Solution {
public:
    int numberOf1Between1AndN_Solution(int n) {
        vector<int> number;
        while(n){
            number.push_back(n % 10);
            n /= 10;
        }

        int s = number.size();
        int res = 0;
        for(int i = 0; i < s; i++){
            int weight = 1;
            int w = i;
            while(w--){
                weight = weight * 10;
            }

            int k = i - 1, right = 0, left = 0;
            while(k >= 0){
                right = right * 10 + number[k];
                k --;
            }
            k = s - 1;
            while(k > i){
                left = left * 10 + number[k];
                k --;
            }

            res += left * weight;
            if(number[i] == 1){
                res += right + 1;
            } else if(number[i] > 1){
                res += weight;
            }
        }

        return res;
    }
};  