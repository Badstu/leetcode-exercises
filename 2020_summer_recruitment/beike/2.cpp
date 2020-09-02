#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int a, b, c;

int main(){
	cin >> a >> b;
	if(a == b){
		cout << "inf" << endl;
		return 0;
	}
	if(a < b){
		cout << 0 << endl;
		return 0;
	}

	if(a == 0){
		if(b == 0){
			cout << "inf" << endl;
			return 0;
		} else{
			cout << 0 << endl;
			return 0;
		}
	}
	

	int x = a - b;
	int count = 0;
	for(int i = 1; (LL)i*i <= x; i++){
		if(x % i != 0) continue;
		int p = i;
		if(a / p * p == x) count++;
		if(x / i != i){
			p = x / i;
			if(a / p*p == x) count++;
		}
	}
	cout << count << endl;
	return 0;
}