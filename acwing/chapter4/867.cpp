#include<iostream>

using namespace std;

void deprime(int x){
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0){
            //求i的次数
            int s = 0;
            while(x % i ==0){
                x /= i;
                s++;
            }
            cout << i << " " << s << endl;
        }
    }
    if(x > 1) cout << x << " " << 1 << endl;
}



int main(){
    int n, a;
    cin >> n;
    while(n--){
        cin >> a;
        deprime(a);
        puts("");
    }
    return 0;
}