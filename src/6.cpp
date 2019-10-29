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
        vector<vector<char>> str_matrix;
        vector<char> temp(numRows, 0);
        int col = 0, i = 0, temp_index = 0;

        if(s.size() == 0){
            return "";
        } else if(numRows == 1){
            return s;
        }

        while(i<=s.size()){
            if(temp_index < numRows){
                if(col % (numRows - 1) == 0){
                    temp[temp_index] = s[i];
                    temp_index++;
                } else{
                    temp_index =  numRows - (col % (numRows - 1)) - 1;
                    temp[temp_index] = s[i];
                    temp_index = numRows;
                }
                i++;
            } else {
                str_matrix.push_back(temp);
                temp.assign(numRows, 0);
                col++;
                temp_index = 0;
            }
        }

        str_matrix.push_back(temp);
        
        string result;
        for (int j = 0; j < numRows; j++){
            for (int i = 0; i < str_matrix.size(); i++){
                if (str_matrix[i][j] != 0){
                    result.push_back(str_matrix[i][j]);
                }
                // cout << str_matrix[i][j] << " ";
            }
            // cout << endl;
        }
        return result;
    }
};
// @lc code=end

