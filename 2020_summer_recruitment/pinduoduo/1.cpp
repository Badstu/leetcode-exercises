#include<bits/stdc++.h>

using namespace std;

int K, N;

int main(){
	cin >> K >> N;
    if(K == 0){
        cout << "paradox" << endl;
        return 0;
    }

	int t, m = 0;
	int sum = 0;
	int flag = 0;
	for(int i = 0; i < N; i++){
		cin >> t;
		if(sum + t == K && i < N){
			sum += t;
			flag = 1;
			break;
		} else if(sum + t < K){
			sum += t;
		} else{
			int back = t + sum - K;
			sum = K - back;
			m++;
		}
	}

	if(flag) cout << "paradox" << endl;
	else cout << K-sum << " " << m << endl;


	return 0;
}