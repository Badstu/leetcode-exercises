#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int maxn = 1e3 + 10;
int n, m, k, t;
vector<PII> c[2];

int main(){
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		c[y - 1].push_back({x, i});
	}

	sort(c[0].begin(), c[0].end());
	reverse(c[0].begin(), c[0].end());

	sort(c[1].begin(), c[1].end());
	reverse(c[1].begin(), c[1].end());

	if((int)c[0].size() < 3 && (int)c[1].size() < 3){
		puts("null");
	} else{
		auto p = c[0];
		int f = 1;
		if((int)c[0].size() < 3) p = c[1], f = 2;
		else if((int)c[1].size() < 3) p = c[0];
		else {
			int x = c[0][2].first + c[0][1].first + c[0][0].first;
			int y = c[1][2].first + c[1][1].first + c[1][0].first;
			if(x < y){
				p = c[1], f = 2;
			} else if(x > y){
				p = c[0];
			} else{
				int _x = min({c[0][2].second, c[0][1].second, c[0][0].second});
				int _y = min({c[1][2].second, c[1][1].second, c[1][0].second});
				if(_x < _y){
					p = c[0];
				} else{
					p = c[1], f = 2;
				}
			}
		}
		printf("%d %d %d\n", p[2].second, p[1].second, p[0].second);
		printf("%d\n", f);
		printf("%d\n", p[2].first + p[1].first + p[0].first);
	}
	return 0;
}