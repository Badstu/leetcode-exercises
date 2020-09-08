#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int dist[N], rest[N]; 

int main(){
	int m, n;
	cin >> m >> n;

	for(int i = 0; i < n; i++){
		cin >> dist[i];
	}

	for(int i = 0; i < n; i++){
		int j = i;
		int minima = dist[i];
		while(j < n && j < i + 4){
			if(dist[j] <= minima){
				minima = dist[j];
				i = j;
			}
			j++;
		}
		rest[i] = 1;
	}

	int total = 0;
	for(int i = 0; i < n; i++){
		if(rest[i] != 1) total += dist[i];

		if(total >= m){
			cout << i + 1 << endl;
			return 0;
		}
	}

	if(total < m){
		cout << -1 << endl;
	}

	return 0;

}