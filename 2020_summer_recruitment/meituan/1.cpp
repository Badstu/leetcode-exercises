#include<bits/stdc++.h>

using namespace std;



int main(){
	int sum = 0, sum_t = 0;
	int t = 0;
	for(int i = 0; i < 5; i++){
		cin >> t;
		sum += (i+1) * t;
		sum_t += t;
	}
	if(sum_t == 0){
		cout << "0.0" << endl;
		return 0;
	}

	double res = (double) sum / sum_t;
	printf("%.1lf\n", res - 0.05);
	
	return 0;
}

//2 2 1 1 2