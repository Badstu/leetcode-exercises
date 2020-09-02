#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;

int primes[N], cnt = 0;
bool st[N];
int prefix_sum[N];

void prime(int x){
	for(int i = 2; i <= x; i++){
		if(!st[i]) {
			primes[cnt++] = i;
			prefix_sum[cnt] = prefix_sum[cnt - 1] + i;
		}

		for(int j = 0; primes[j] <= x / i; j++){
			st[i * primes[j]] = true;
			if(i % primes[j] == 0) break;
		}
	}
}


int main(){
	int n;
	cin >> n;
	prime(n);

	int count = 0;
	for(int i = 1; i <= cnt; i++){
		for(int j = i; j <= cnt; j++){
			if(prefix_sum[j] - prefix_sum[i-1] == n){
				count ++;
			}
		}
	}
	cout << count << endl;
	return 0;
}