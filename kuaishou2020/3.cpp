#include <iostream>
// #include <map>
#include <unordered_set>
using namespace std;
const int N = 2e5+10, T = 20;
int A0[N], A1[N]


void generate(int s0, int a0, int b0, int p0, int s1, int a1, int b1, int p1){
	int x = s0, idx = 0;
	unordered_set<int> S;
	while(!S.count(x)){
		A0[idx++] = x; 
		S.insert(x);
		x = (x * a0 + b0) % p0;
	}

	int x = s1, idx = 0;
	unordered_set<int> S;
	while(!S.count(x)){
		A1[idx++] = x; 
		S.insert(x);
		x = (x * a1 + b1) % p1;
	}
}

void cout_list(){}

/*
3
4 2 1 6
4 3 1 6
1 1 1 100
1 1 99 100
1 23 1 100007
1 23 1 100007
*/

/*
3
4
98880
*/

int main(){
	int t;
	cin >> t;
	while(t --){
		int s0, a0, b0, p0;
		int s1, a1, b1, p1;
		cin >> s0 >> a0 >> b0 >> p0;
		cin >> s1 >> a1 >> b1 >> p1;
		generate(s0, a0, b0, p0, s1, a1, b1, p1) << endl;
	}
	return 0;
}