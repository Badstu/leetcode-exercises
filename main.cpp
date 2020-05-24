#include <bits/stdc++.h>

using namespace std;


int getMinimumUniqueSum(vector<int> arr) {
    if(arr.empty()) return 0;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    // int i = 0, j = 0;
    int res = 0;
    int tmp = 1;
    for(int i = 0, j = 1; i < n; i++, j++){
        while(arr[i] == arr[j]){
            arr[j] += tmp;
            tmp++;
            j++;
        }
        res += arr[i];
    }

    for(int x: arr){
        cout << x << " ";
        res += x;
    }
    return res;

}

int main(){
    // vector<int> arr = {1659, 710, 710, 1730, 1808, 2043, 1613, 1841, 1328, 504, 1730, 2545, 493, 879, 1441, 2043, 1613, 710, 1613, 1250};
    
    cout << "helloworld" << endl;
    return 0;
}
/*
1999999999
*/