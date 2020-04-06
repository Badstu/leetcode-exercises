#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string rollTheString(string s, vector<int> roll) {
    string res;
    int number = roll.size();

    priority_queue<int, vector<int>, greater<int>> heap;
    for(x: roll) heap.push(x);

    int last = 0;
    while(heap.size()){
        int min = heap.top();
        heap.pop();
        for(int i = last; i < min; i ++){
            char c = (s[i] - 'a' + number) % 26 + 'a';
            res += c;
        }
        number --;
        last = min;
    }

    int max_r = *(max_element(roll.begin(), roll.end()));
    int n_s = s.size();
    
    while(max_r < n_s){
        res += s[max_r];
        max_r ++;
    }

    return res;
}


int main(){
    string s = "vgxgpuamkx";
    vector<int> roll = {5, 5, 2, 4, 7, 6, 2, 2, 8, 7};
    cout << rollTheString(s, roll);
    return 0;
}