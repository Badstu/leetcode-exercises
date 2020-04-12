class Solution {
public:
    int strToInt(string str) {
        int k = 0;
        while(str[k] == ' ') k++;
        bool is_minus = false;
        if(str[k] == '-'){
            is_minus = true;
            k++;
        } else if(str[k] == '+'){
            k++;
        }

        long long ans = 0;
        while(k < str.size() && str[k] >= '0' && str[k] <= '9'){
            ans = ans * 10 + str[k] - '0';
            k++;
        }

        ans = is_minus ? ans * -1: ans;
        if(ans > INT_MAX) ans = INT_MAX;
        if(ans < INT_MIN) ans = INT_MIN;

        return ans;
    }
};