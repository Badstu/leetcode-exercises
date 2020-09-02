#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10;
int n, m, k, t;
int d[maxn];
int cnt;

int main(){
	int i, j;
	scanf("%d", &m);

	while(m--){
		int op;
		scanf("%d", &op);
		if(op == 1){
			scanf("%d%d", &j, &k);
			for(i = cnt; i >= j; i--){
				d[i+1] = d[i];
			}
			d[j] = k;
			cnt ++;
		} else if(op == 2){
			scanf("%d", &j);
			for(i = j; i <= cnt - 1; i++){
				d[i] = d[i+1];
			}
			cnt --;
		} else{
			for(i = 1; i <= cnt; i++){
				printf("%d%c", d[i], i == cnt?'\n':' ');
			}
		}

	}
	return 0;
}