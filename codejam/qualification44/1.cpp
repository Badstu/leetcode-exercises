#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 110;

vector<vector<int>> matrix(N, vector<int>(N, 0));
int h[N], v[N];
bool st[N];

int main(){
    int t = 0, n = 0;
    cin >> t;
    for(int ca = 1; ca <= t; ca++){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> matrix[i][j];
            }
        }

        int trace = 0;
        for(int i = 0; i < n; i++){
            trace += matrix[i][i];
        }
        int repeat_row = 0, repeat_col = 0;
        for(int i = 0; i < n; i++){
            memset(h, 0, sizeof h);
            for(int j = 0; j < n; j++){
                int num = matrix[i][j];
                if(h[num] == 1){
                    repeat_row ++;
                    break;
                }
                h[num] = 1;
            }
        }

        for(int i = 0; i < n; i++){
            memset(v, 0, sizeof v);
            for(int j = 0; j < n; j++){
                int num = matrix[j][i];
                if(v[num] == 1){
                    repeat_col ++;
                    break;
                }
                v[num] = 1;
            }
        }
        cout << "Case #" << ca << ": " << trace << " " << repeat_row << " " << repeat_col << endl;
    }
    return 0;
}

/*
3
4
1 2 3 4
2 1 4 3
3 4 1 2
4 3 2 1
4
2 2 2 2
2 3 2 3
2 2 2 3
2 2 2 2
3
2 1 3
1 3 2
1 2 3
*/
