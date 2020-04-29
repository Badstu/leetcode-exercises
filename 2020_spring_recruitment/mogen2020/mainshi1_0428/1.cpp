#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;


bool is_equal(vector<int>& numbers){
    bool flag = true;
    int t = numbers[0];
    for(int i = 1; i < numbers.size(); i++){
        if(numbers[i] != t){
            flag = false;
            break;
        }
    }
    return flag;
}

long countMoves(vector<int> numbers){
    int n = numbers.size();
    int times = 0;
    
    sort(numbers.begin(), numbers.end());

    while(!is_equal(numbers)){
        int ii = n - 2;
        while(ii >= 0 && numbers[ii] > numbers[n-1]){
            ii --;
        }
        swap(numbers[ii+1], numbers[n-1]);

        numbers[n-1] -= 1;
        times++;
    }
    return times;
}

int main(){
    // vector<int> a = {5, 6, 8, 8, 5} ;
    vector<int> a = {3, 4, 6, 6, 3};
    cout << countMoves(a);
    return 0;
}
