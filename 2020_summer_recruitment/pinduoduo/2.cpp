#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int a[6], b[6];
unordered_map<string, int> hash_map;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++){
			scanf("%d", &a[j]);
		}
		swap(a[2], a[4]);
		swap(a[3], a[5]);

		for(int j = 0; j < 6; j++){
			if(a[j] != 1) continue;
			if(j == 1){
				swap(a[0], a[1]);
				swap(a[2], a[3]);
			}
			if(j == 2){
				memcpy(b, a, sizeof(b));
				a[0] = b[2];
				a[1] = b[3];
				a[2] = b[1];
				a[3] = b[0];
			}
			if(j == 3){
				memcpy(b, a, sizeof(b));
				a[0] = b[3];
				a[1] = b[2];
				a[2] = b[0];
				a[3] = b[1];
			}
			if(j == 4){
				memcpy(b, a, sizeof(b));
				a[0] = b[4];
				a[1] = b[5];
				a[2] = b[1];
				a[3] = b[0];
			}
			if(j == 5){
				memcpy(b, a, sizeof(b));
				a[0] = b[5];
				a[1] = b[4];
				a[2] = b[0];
				a[3] = b[1];
			}
			break;
		}
		while(a[2] < a[3] || a[2] < a[4] || a[2] < a[5]){
			b[0] = a[0];
			b[1] = a[1];
			b[2] = a[5];
			b[3] = a[4];
			b[4] = a[2];
			b[5] = a[3];
			memcpy(a, b, sizeof(b[0]) * 6);
		}
		string temp;
		for(int j = 0; j < 6; j++){
			temp += a[j] + '0';
		}
		hash_map[temp] ++;
	}

	vector<int> ans;
	for(auto x: hash_map){
		ans.push_back(x.second);
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	
	cout << (int)ans.size() << endl;
	for(int x: ans){
		cout << x << " ";
	}

	return 0;
}