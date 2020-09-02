#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4+10;
int a[maxn], b[maxn], c[maxn];

int main(){
	int n;
	cin >> n;

	int value = 0, pay = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];

		if(a[i] > b[i]){
			c[i] = a[i] - b[i];
			value += a[i];
		} else{
			c[i] = 0;
			value += b[i];
		}
		
		pay += c[i];
	}

	cout << value << " " << pay << endl;

	return 0;
}