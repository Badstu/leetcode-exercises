#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        if(array.empty() || array[0].empty()) return false;
        int n = array.size(); int m = array[0].size();
        int i = 0, j = m - 1;

        while(i < n && j >= 0){
            int sel = array[i][j];
            if(sel == target) return true;
            else if(sel > target){
                j --;
            } else if(sel < target){
                i ++;
            }
        }
        return false;
    }
};


int main(){
    Solution s;
    vector<vector<int>> array = {{1,2,8,9},
                                {2,4,9,12},
                                {4,7,10,13},
                                {6,8,11,15}};
    int target = 0;
    cout << s.searchArray(array, target);
}