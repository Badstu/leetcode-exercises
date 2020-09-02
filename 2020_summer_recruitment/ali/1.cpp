#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+10;
int T;
int q[N];

int main(){
	cin >> T;
	int n = 0;
	while(T--){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> q[i];
		}

		int k = n-1, old_i = q[k];
		while(k >= 0){
			int count = 0;
			while(k >= 0 && q[k] == old_i){
				count ++;
				k--;
			}

			if(count % 2 != 0){
				cout << "NIUNIU" << endl;
				break;
			} else{
				if(k < 0){
					cout << "NIUMEI" << endl;
					break;
				} else{
					old_i = q[k];
				}
			}
		}
	}
	
	return 0;
}