#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int superEggDrop(int K, int N) {
        int f[K + 1][N + 1];
        memset(f, 0, sizeof f);
        for(int i = 0; i <= N; i++) f[1][i] = i;

        int x0, x1;
        for(int i = 2; i <= K; i++){
            for(int j = 1; j <= N; j++){
                int l = 1, r = j;
                while(l < r){
                    int mid = l + r + 1 >> 1;
                    if(f[i - 1][mid - 1] <= f[i][j - mid]) l = mid;
                    else r = mid - 1;
                }
                
                x0 = l, x1 = l + 1;
                int max_x1, max_x2 = 1e9;
                max_x1 = max(f[i - 1][x0 - 1], f[i][j - x0]);
                if(x1 <= j){
                    max_x2 = max(f[i - 1][x1 - 1], f[i][j - x1]);
                }
                f[i][j] = 1 + min(max_x1, max_x2);
            }
        }
        for(int i = 0; i <= K; i++){
            for(int j = 0; j <= N; j++){
                cout << f[i][j] << " ";
            }
            cout << endl;
        }
        return f[K][N];
    }
    
};


int main(){
    cout << "helloworld" << endl;
    Solution s;
    
    cout << s.superEggDrop(3, 14);

    return 0;
}
