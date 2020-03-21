// #include <iostream>
// #include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 5e4+10;
PII cows[N];

int main(){
	int n;
	cin >> n;

	int w, s;
	for(int i = 0; i < n; i++){
		cin >> w >> s;
		cows[i] = {w + s, s};
	}

	sort(cows, cows + n);

	int max_risk = -2e9, all_weight = 0;
	for(int i = 0; i < n; i++){
		int s = cows[i].second, w = cows[i].first - s;
		max_risk = max(max_risk, all_weight - s);
		all_weight += w;
	}

	cout << max_risk;
	return 0;
}