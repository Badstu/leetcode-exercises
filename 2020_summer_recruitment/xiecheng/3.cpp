#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10;
typedef long long LL;
int n, m, k, t;
char a[maxn];

int trans(char x){
	if(x >= 'a' && x <= 'z'){
		return x - 'a' + 1;
	}
	if(x >= 'A' && x <= 'Z'){
		return 27 + x - 'A';
	}
	if(x >= '0' && x <= '9'){
		return 53 + x - '0';
	}
	return 0;
}

int main(){
	int i, j;
	while(~scanf("%s", a)){
		int len = strlen(a);
		int first = 1;
		for(i = 0; i < len; i+=5){
			int ed = min(i + 5 - 1, len - 1);
			int x = 0;
			for(j = i; j <= ed; j++){
				x = x * (1 << 6) + trans(a[j]);
			}
			if(!first) printf(" ");
			else first = 0;
			printf("%d", x);
		}
		puts(" ");		
	}
	return 0;
}