#include <iostream>

using namespace std;

bool prime(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}


int main(){
    int n, a;
    cin >> n;
    while(n --){
        cin >> a;
        if(prime(a)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}