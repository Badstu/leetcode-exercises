#include <iostream>

using namespace std;

int main(){

    int a = 10;
    int b = 111;

    a = 1000;
    b = 1111;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)
            cout << "* ";
            
        cout << endl;
    }
    return 0;
}
