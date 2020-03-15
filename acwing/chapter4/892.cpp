#include <iostream>

using namespace std;

int main(){
    int n, a;
    cin >> n;

    int res = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(i % 2 == 0){
            res ^= a;
        }
    }

    if(res) cout << "Yes";
    else cout << "No";

    return 0;
}