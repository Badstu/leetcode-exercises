#include <iostream>

using namespace std;

const int N = 110;
int q[N];

int main(){
    int t, b;
    cin >> t >> b;

    while(t--){
        if(b == 10){
            for(int i = 1; i <= b; i++){
                cout << i << endl;
                cin >> q[i];
            }
        } else if(b == 20){

        } else if(b == 100){

        }

        for(int i = 1; i <= b; i++){
            cout << q[i];
        }
        cout << endl;

        char c; 
        cin >> c;
        if(c == 'N'){
            break;
        }
    }

    return 0;
}