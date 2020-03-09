#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100;

vector<int> get_divisors(int n){
    vector<int> result;
    
    for(int i = 1; i <= n / i; i++){
        if(n % i == 0){
            result.push_back(i);
            if(i !=  n / i) result.push_back(n / i);
        }
    }

    sort(result.begin(), result.end());
    return result;
}


int main(){
    int n, a;
    cin >> n;
    while(n--){
        cin >> a;
        vector<int> res = get_divisors(a);
        for(int i = 0; i< res.size(); i++){
            cout << res[i] << " ";
        }
        puts("");
    }

    return 0;
}