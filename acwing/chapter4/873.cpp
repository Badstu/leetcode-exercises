#include <iostream>

using namespace std;

int get_eulur(int n){
    int phi = n;
    for(int i = 2; i <= n / i; i ++){
        if( n % i == 0){
            phi = phi - phi / i;
            // phi = phi / i * (i - 1);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) phi = phi - phi / n;

    return phi;
}


int main(){
    int n, a;
    cin >> n;

    while(n --){
        cin >> a;
        cout << get_eulur(a) << endl;
    }
    return 0;
}