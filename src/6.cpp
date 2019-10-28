/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int length = s.size();
        int rows = numRows, cols = 0;
        int gap_cols = numRows - 2;

        vector<vector<int>> str_matrix;
        vector<int> temp;
        for(int i = 0; i < s.size(); ++i){
            if(temp.size() < rows){
                temp.push_back(s[i]);
                
            }
        }

    }
};
// @lc code=end

