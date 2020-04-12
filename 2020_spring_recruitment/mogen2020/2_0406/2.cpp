#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'ways' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER total
 *  2. INTEGER k
 */

int ways(int total, int k) {
    int MOD = 1e9+7;
    int f[k+1][total+1];

    memset(f, 0, sizeof f);
    for(int i = 0; i <= k; i++) f[i][0] = 1;

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= total; j++){
            for(int t = 0; t * i <= j; t++){
                f[i][j] = (f[i][j] + f[i - 1][j - t * i]) % MOD;
            }
        }
    }
    return f[k][total];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string total_temp;
    getline(cin, total_temp);

    int total = stoi(ltrim(rtrim(total_temp)));

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    int result = ways(total, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
