#include <iostream>

using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b, a){
        if(a > b) swap(a, b);
        for(int i = 0; i <= 9; i++){
            cout << count(b, i) - count(a - 1, i) << " ";
        }
        cout << endl;
    }

    return 0;
}