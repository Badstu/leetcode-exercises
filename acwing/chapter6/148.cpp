#include <iostream>
#include <queue>
using namespace std;

const int N = 1e4+10;

int main(){
	priority_queue<int, vector<int>, greater<int>> heap;

	int n, a;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		heap.push(a);
	}
	
	int res = 0;
	for(int i = 0; i < n - 1; i++){
		int a = heap.top(); heap.pop();
		int b = heap.top(); heap.pop();
		heap.push(a + b); //两个节点合并成一个新的节点

		res = res + a + b; //总的体力
	}
	cout << res; //要输出总的体力

	return 0;
}