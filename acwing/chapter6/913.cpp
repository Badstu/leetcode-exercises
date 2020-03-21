#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
int a[N];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a + n);

	long long sum = 0;
	for(int i = 0; i < n; i ++){
		sum += a[i] * (n - i - 1);
	}
	cout << sum;

	return 0;
}