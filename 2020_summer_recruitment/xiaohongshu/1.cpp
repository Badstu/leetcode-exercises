#include<bits/stdc++.h>

using namespace std;

const int N = 1010;
stack<int> stk;

int main(){
	char t;
	while(scanf("%s", &t) != EOF){
		if(t <= '9' && t >= '0'){
			// res += (t - '0');
			stk.push(t - '0');
		} else if(t == '+'){
			if(stk.empty()) continue;
			if(stk.size() == 1){
				stk.push(stk.top());
				continue;
			}
			int top1 = stk.top();
			stk.pop();
			int top2 = stk.top();
			stk.pop();
			// res += (top1 + top2);
			stk.push(top2), stk.push(top1), stk.push(top1 + top2);
		} else if(t == 'T'){
			// res += (stk.top() * 3);
			if(stk.empty()) continue;
			stk.push(stk.top() * 3);
		} else if(t == '-'){
			if(stk.empty()) continue;
			if(stk.size() == 1){
				stk.push(stk.top());
				continue;
			}
			int top1 = stk.top();
			stk.pop();
			int top2 = stk.top();
			stk.pop();
			// res += abs(top1 - top2);
			// cout << top1 << " " << top2 << endl;
			stk.push(top2), stk.push(top1), stk.push(abs(top1 - top2));
		} else if(t == 'C'){
			if(stk.empty()) continue;
			// res -= stk.top();
			stk.pop();
		}
	}

	int res = 0;
	while(stk.size()){
		res += stk.top();
		stk.pop();
	}

	cout << res << endl;
	return 0;
}