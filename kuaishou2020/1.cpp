#include <iostream>

using namespace std;

const int N = 1010, K = 12;
long long f[K][N];
int n, k;

void cout_matrix(){
	cout << endl;
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
}


int main(){
	cin >> k >> n;

	for(int i = 1; i <= n; i++) f[1][i] =  i;

	// cout_matrix();

	for(int j = 2; j <= n; j++){
		for(int i = 2; i <= k; i++){
			for(int s = 1; s <= j - i - 1; s++){
				f[i][j] = max(f[i][j], (long long)f[i - 1][j - s] * s);
			}
		}
	}

	// cout << "-------------" << endl;
	// cout_matrix();
	cout << f[k][n];

	return 0;
}