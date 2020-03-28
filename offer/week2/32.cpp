#include <iostream>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &a) {
        int l = 0, r = a.size() - 1;
        while(l < r){
            while(l < r && a[l] % 2 == 1) l++;
            while(l < r && a[r] % 2 == 0) r--;
            if(l < r) swap(a[l], a[r]);
        }
    }
};