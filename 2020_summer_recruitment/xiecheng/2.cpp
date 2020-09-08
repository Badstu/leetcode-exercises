#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> res;

int main(){
	int h, w;
	cin >> h >> w;
	res = vector<vector<int>>(h, vector<int>(w, 0));

	if(h == 1 && w == 1){
		cout << "[[1]]" << endl;
		return 0;
	}

	int k = h + w - 2;
	int t = 1;
	for(int i = 0; i <= k; i++){
		for(int y = i, x = 0; y >= 0; y--, x++){
			if(y >= h || x >= w){
				continue;
			}
			res[y][x] = t++;
		}
	}

	string ans = "[";
	for(int i = 0; i < h; i++){
		ans += "[";
		for(int j = 0; j < w; j++){
			ans += to_string(res[i][j]);
			if(j < w - 1){
				ans += ",";
			}
		}
		ans += "]";
		if(i < h - 1) ans += ",";
	}
	ans += "]";

	cout << ans << endl;
	return 0;
}