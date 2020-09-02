class Solution {
public:
    /**
     * 
     * @param num int整型 
     * @return int整型vector
     */
    vector<int> countBits(int num) {
        // write code here
		vector<int> res(num + 1, 0);
		
		for(int i = 1; i <= num; i++){
			res[i] = res[i & (i - 1)] + 1;
		}

		return res;
    }
};