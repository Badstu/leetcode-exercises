#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+10;
int chongbai[N];
int piao[N];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> chongbai[i];
	}

	memset(piao, 0, sizeof piao);

	for(int i = 0; i < n; i++){
		int t = chongbai[i];
		while(t != 0){
			piao[t] ++;
			t = chongbai[t - 1];
		}
	}

	for(int i = 1; i <= n; i++){
		cout << piao[i] + 1 << endl;
	}

	return 0;
}


/*
4
0 1 1 1
*/